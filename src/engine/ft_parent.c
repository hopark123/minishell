#include "head.h"

pid_t	ft_parent(pid_t pid, int *status)
{
	pid_t	w_pid;

	while (!WIFEXITED(*status) && !WIFSIGNALED(*status))
		w_pid = waitpid(pid, status, WUNTRACED);
	return (0);
}
