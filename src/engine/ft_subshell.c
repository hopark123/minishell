#include "head.h"

static int	**free_pipe(int ***pipe, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		free((*pipe)[i]);
		i++;
	}
	free(*pipe);
	return (0);
}

static int	count_pipe(t_built *built)
{
	int	i;
	t_built	*tmp;
	
	i = 0;
	tmp = built;
	if (tmp)
	{
		while (tmp->next && tmp->next->command->str[0] == '|')
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

static int	**init_pipe(int size)
{
	int	j;
	int	**pip;

	j = 0;
	pip = (int **)malloc(sizeof(int *) * size);
	if (!pip)
		return (0);
	while (j < size)
	{
		pip[j] = (int *)malloc(sizeof(int) * 2);
		if (!pip[j] || pipe(pip[j]) == -1)
			return (free_pipe(&pip, j));
		j++;
	}
	return (pip);
}

static void	close_pip_parent(int **fd, int order, int size)
{
	int	i;

	i = 0;
	while (i <= order && i < size)
		ft_close(fd[i++][1]);	
}

static void	close_pip_child(int **fd, int size, int in_index, int out_index)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == in_index)
			ft_close(fd[i][1]);	
		else if (i == out_index)
			ft_close(fd[i][0]);
		else
		{
			ft_close(fd[i][0]);
			ft_close(fd[i][1]);
		}
		i++;
	}
}

int ft_start(t_built *built, t_list *env_list)
{
	int	**fd;
	int	status;
	int	order;
	int	size;

	status = 1;
	while (built)
	{
		if (built->next && built->next->command->str[0] == '|')
		{
			order = 0;
			size = count_pipe(built);
			printf("pipsize: %d\n", size);
			fd = init_pipe(size);
			if (!fd)
				return (-1);
			while (built && order <= size)
			{
				status = ft_subshell(built, env_list, fd, order, size);
				built = built->next;
				order++;
			}
		}
		else
		{
			status = ft_execute(built, env_list);
			built = built->next;
		}
	}

	return (status);
}

static void	do_piping(int pip_in, int pip_out)
{
	if (pip_in != -1)
	{
		if (dup2(pip_in, STDIN) < 0)
			perror("pipe_in:error");
		if (pip_in > 0)
			close(pip_in);
	}
	if (pip_out != -1)
	{
		if (dup2(pip_out, STDOUT) < 0)
			perror("pipe_out:error");
		if (pip_out == 0 || pip_out > 1)
			close(pip_out);
	}
}

int	ft_subshell(t_built *built, t_list *env_list, int **fd, int order, int size)
{
	int	status;
	int	w_status;
	pid_t	pid;
	pid_t	w_pid;

	pid = fork();
	if (pid < 0)
	{
		perror("forkerror");
		return (ERROR);
	}
	if (pid == 0) //자식
	{
		if (order == 0)
			do_piping(-1, fd[order][1]);
		else if (order == size)
			do_piping(fd[order - 1][0], -1);
		else
			do_piping(fd[order - 1][0], fd[order][1]);
		close_pip_child(fd, size, order - 1, order);
		status = ft_execute(built, env_list);
		exit(status);
	}
	else // 부모
	{
		close_pip_parent(fd, order, size);
		w_pid = waitpid(pid, &w_status, WUNTRACED);
		while (!WIFEXITED(w_status) && !WIFSIGNALED(status))
			w_pid = waitpid(pid, &w_status, WUNTRACED);
	}
	return (w_status);
}
