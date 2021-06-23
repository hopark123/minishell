
#include "head.h"

int ft_start(t_built *built, t_list *env_list)
{
	int		p_fd[2];

	p_fd[0] = STDIN;
	p_fd[1] = STDOUT;
	if (built->next && built->next->command->str[0] == '|')
	{
		while (built)
		{
			// write(1,"3@",2);
			ft_subshell(built, env_list, p_fd);
			p_fd[1] = dup(p_fd[0]);
			// printf("%d\n", p_fd[1]);
			// get_next_line(p_fd[0], &line);
			// printf("%s\n", line);
			if (built->next && built->next->command->str[0] != '|')
				break ;
			built = built->next;
		}
		ft_close(p_fd[1]);
	}
	else
	{
		write(1,"&&",2);
		ft_execute(built, env_list);
	}
	return (1);
}

int	ft_subshell(t_built *built, t_list *env_list, int *p_fd)
{
	int	status;
	int	w_status;
	pid_t	pid;
	pid_t	w_pid;
	int	fd[2];

	if (pipe(fd) < 0)
	{
		perror("pipeerror");
		return (ERROR);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("forkerror");
		return (ERROR);
	}
	if (pid == 0) //자식
	{
		dup2(fd[0], STDIN);
		dup2(fd[1], STDOUT);
		close(fd[0]);
		status = ft_execute(built, env_list);
		// if (!built->next || built->next->command->str[0] != '|')
		// {
		// 	exit(status);
		// }
		// exit(status | ft_subshell(built->next, env_list));
		exit(status);
	}
	else // 부모
	{
		// dup2(fd[1], STDOUT);
		dup2(p_fd[1], fd[0]);
		// ft_close(fd[0]);
		w_pid = waitpid(pid, &w_status, WUNTRACED);
		while (!WIFEXITED(w_status) && !WIFSIGNALED(status))
			w_pid = waitpid(pid, &w_status, WUNTRACED);
		
		char *line;
		write(1,"a",1);
		printf("d : %d %d\n", p_fd[0], p_fd[1]);
		get_next_line(p_fd[1], &line);
		write(1,"c",1);
		printf("[%s]\n", line);
		
		p_fd[0] = fd[1]; 
		// p_fd[0] = dup(fd[1]);
		
		
		ft_close(p_fd[1]);
		// dup2(fd[1], p_fd[0]);
	}
	return (w_status);
}
