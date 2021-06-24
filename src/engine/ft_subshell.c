
#include "head.h"

static void	close_pip(int pip_in, int pip_out)
{
	if (pip_in >= 0)
		close(pip_in);
	if (pip_out >= 0)
		close(pip_out);
}

int ft_start(t_built *built, t_list *env_list)
{
	int	fd[2];

	if (built->next && built->next->command->str[0] == '|')
	{
		if (pipe(fd) < 0)
		{
			perror("pipeerror");
			return (ERROR);
		}
		while (built)
		{
			ft_subshell(built, env_list, fd);
			if (built->next && built->next->command->str[0] != '|')
				break ;
			// printf("[%s]end subshell\n", built->command->str);
			dup2 (STDIN , fd[1]);
			// printf("[%s]end dup2\n", built->command->str);
			built = built->next;
		}
		close_pip(fd[0], fd[1]);
	}
	else
		ft_execute(built, env_list);
	return (1);
}

static void	do_piping(int pip_in, int pip_out)
{
	// printf("pipin:%d pipout:%d \n", pip_in, pip_out);
	if (pip_in != -1)
	{
		if (dup2(pip_in, STDIN) < 0)
			perror("pipe_in:error");
		ft_close(pip_in);

	}
	if (pip_out != -1)
	{
		if (dup2(pip_out, STDOUT) < 0)
			perror("pipe_out:error");
		ft_close(pip_out);

	}
}

int	ft_subshell(t_built *built, t_list *env_list, int *fd)
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
		do_piping(fd[0], fd[1]);
		// write(1, "aaa\n", 4);
		status = ft_execute(built, env_list);
		// write(1, "bbb\n", 4);
		exit(status);
	}
	else // 부모
	{
		w_pid = waitpid(pid, &w_status, WUNTRACED);
		while (!WIFEXITED(w_status) && !WIFSIGNALED(status))
			w_pid = waitpid(pid, &w_status, WUNTRACED);
	}
	return (w_status);
}
