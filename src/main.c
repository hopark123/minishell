/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongseonghyeon <hongseonghyeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:52:01 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/05 07:04:58 by hongseonghy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "type.h"

void	minishell(t_list *env_list)
{
	t_list	*list;
	t_built	*built;

	list = ft_token_split(g_mini.line);
		fprintf(stderr, "[%p]\n", list);
	ft_envswap(list, env_list);
		fprintf(stderr, "[%p]\n", list);
	ft_del_quotes(list);
		fprintf(stderr, "[%p]\n", list);
	built = ft_builtndup(list);
		fprintf(stderr, "[%p]\n", list);
	ft_del_blank(built);
		fprintf(stderr, "[%p]\n", list);
	ft_put_blank(built);
		fprintf(stderr, "[%p]\n", list);
	ft_del_lastblank(built);
	// test_print_passing(built);
		fprintf(stderr, "[%p]\n", list);
	ft_split_built(built, "|;");
	ft_shell(built, &env_list);
	ft_free(g_mini.line);
}

void	loop(t_list *env_list)
{
	while (1)
	{
		draw2();
		ft_prompt_signal();
		ft_init_term();
		ft_get_line();
		ft_reset_term();
		if (ft_strlen(g_mini.line))
		{
			if (ft_check_syntax(g_mini.line) == SUCCESS)
				minishell(env_list);
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
	draw();
	loop(env_list);
	ft_listclear(&env_list);
	ft_listclear(&g_mini.history);
	return (g_mini.status);
}
