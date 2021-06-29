#include "suhong.h"

static int	run_subshell(t_built **built, t_list *env_list)
{
	int	order;
	int	**fd;
	int	size;
	int	status;

	order = 0;
	size = count_pipe(*built);
	fd = init_pipe(size);
	if (!fd)
		return (-1);
	while (*built && order <= size)
	{
		status = ft_subshell(*built, env_list, fd, order);
		*built = (*built)->next;
		order++;
	}
	free_pipe(&fd, size);	
	return (status);
}

int	ft_shell(t_built *built, t_list *env_list)
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
			run_subshell(&built, env_list);
		}
		else
		{
			fprintf(stderr, "promptpid : %d, pgid : %d\n", getpid(), getpgid(getpid()));
			status = ft_execute(built, env_list);
			built = built->next;
		}
	}
	return (status);
}
