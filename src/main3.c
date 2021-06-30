#include "head.h"

void	loop(t_list *env_list)
{
	t_built	*built;
	int		status;
	t_built	*temp;
	char	*c;
	char	*temp2;
	
	status = SUCCESS;

	while (status)
	{
		draw2();
		ft_signal();
		g_mini.pip[0] = dup(STDIN);
		g_mini.pip[1] = dup(STDOUT);
		ft_init_term();
		ft_get_line();
		ft_reset_term();
		// if (get_next_line(STDIN, &g_mini.line) > 0)
		if (g_mini.line)
		{
			fprintf(stderr, "gnl:[%s]\n", g_mini.line);
			built = ft_parse(g_mini.line, env_list);
			status = ft_shell(built, env_list);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*env_list;

	env_list = ft_init_env_list(envp);
	// draw();
	loop(env_list);
	ft_listclear(&env_list);
	return (0);
}
