#include "head.h"

int	ft_subshell(t_built *built, t_list *env_list)
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
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		status = ft_execute(built, env_list);
		if (built->next && status > 0)
			if (built->next->command->str[0] == '|')
				status = ft_subshell(built->next, env_list);
		// exit(status);
		return (status);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		w_pid = waitpid(pid, &w_status, WUNTRACED);
		while (!WIFEXITED(w_status) && !WIFSIGNALED(status))
			w_pid = waitpid(pid, &w_status, WUNTRACED);
	}
	return (status);
}
