
#include "head.h"

void	loop(t_list *env_list)
{
	t_built	*built;
	t_list	*list;

	while (1)
	{
		draw2();
		ft_prompt_signal();
		ft_init_term();
		ft_get_line();
		ft_reset_term();
		if (g_mini.line)
		{
			if (ft_check_syntax(g_mini.line) == SUCCESS)
			{
				list = ft_token_split(g_mini.line);
				ft_envswap(list, env_list);
				ft_del_quotes(list);
				built = ft_builtndup(list);
				ft_put_blank(built);
				ft_split_built(built, "|;");
				test_print_passing(built);
				// test_built_list(built);
				ft_free(g_mini.line);
				ft_shell(built, &env_list);
											// t_list *tmp = token;
											// while (tmp)
											// {
											// 	fprintf(stderr, "[id:%s][%s]\n", tmp->id, tmp->str);
											// 	tmp = tmp->next;
											// }
											// ft_listclear(&token);
				// built = ft_parse(g_mini.line, env_list);
				ft_builtclear(&built);
			}
		}
	}
}

void	ft_init_mini(void)
{
	g_mini.pid = -1;
	g_mini.history = ft_listnew(0, 0);
	g_mini.history->next = g_mini.history;
	g_mini.history->prev = g_mini.history;
	g_mini.head = g_mini.history;
	g_mini.head->next = g_mini.history;
	g_mini.head->prev = g_mini.history;
	g_mini.pip[0] = dup(STDIN);
	g_mini.pip[1] = dup(STDOUT);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*env_list;

	(void)argc;
	(void)argv;
	env_list = ft_init_env_list(envp);
	ft_init_mini();
	// draw();
	loop(env_list);
	ft_listclear(&env_list);
	ft_listclear(&g_mini.history);
	return (g_mini.status);
}
