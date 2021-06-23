#include "head.h"

int	ft_subshell(t_built *built, t_list *env_list)
{
	int	status;
	int	w_status;
	pid_t	pid;
	pid_t	w_pid;
	int	fd[2];

	// if (pipe(fd) < 0)
	// {
	// 	perror("pipeerror");
	// 	return (ERROR);
	// }
	pid = fork();
	if (pid < 0)
	{
		perror("forkerror");
		return (ERROR);
	}
	if (pid == 0)
	{
		dup2(fd[0], STDIN);
		close(fd[1]);
		status = ft_execute(built, env_list);
		if (!built->next || built->next->command->str[0] != '|')
		{
			exit(status);
		}
		exit(status | ft_subshell(built->next, env_list));
	}
	else
	{
		dup2(fd[1], STDOUT);
		close(fd[0]);
		w_pid = waitpid(pid, &w_status, WUNTRACED);
		while (!WIFEXITED(w_status) && !WIFSIGNALED(status))
			w_pid = waitpid(pid, &w_status, WUNTRACED);
	}
	return (w_status);
}
