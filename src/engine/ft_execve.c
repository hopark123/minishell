#include "head.h"

int	ft_execve(t_built *built, t_list *env_list)
{
	pid_t	pid;
	pid_t	w_pid;
	int	status;
	char	**argv;
	char	**envp;
	
	argv = ft_listtochar(built->command);
	envp = ft_listtochar(env_list);

	pid = fork();
	if (pid < 0)
	{
		//error
		perror("error");
		return (-1);
	}
	else if (pid == 0)
	{
		//child
		if (execve(argv[0], argv, envp) < 0)
		{
			perror("error");
			return (-1);
		}
	}
	else
	{
		//parent
		w_pid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			w_pid = waitpid(pid, &status, WUNTRACED);
		}
	}
	return (1);
}
