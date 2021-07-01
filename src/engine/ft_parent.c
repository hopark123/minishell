#include "head.h"

int	ft_status_control(int status)
{
	int	signal;

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		return (128 + signal);
	}
	return (ERROR);
}

void	ft_parent(pid_t pid, int *status)
{
	waitpid(pid, status, WUNTRACED);
	while (!WIFEXITED(*status) && !WIFSIGNALED(*status))
		waitpid(pid, status, WUNTRACED);
}
