/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:13:25 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/05 15:42:11 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		kill(g_mini.pid, SIGINT);
		signal(SIGINT, proc_signal_handler);
	}
	if (signo == SIGQUIT)
	{
		kill(g_mini.pid, SIGQUIT);
		printf("Quit: %d\n", signo);
		signal(SIGQUIT, proc_signal_handler);
	}
}

void	signal_handler(int signo)
{
	// ft_listclear(&g_mini.head);
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1, 0);
		ft_init_get_line(&g_mini.cursor, &g_mini.len);

		// ft_listclear(&g_mini.head);
		// ft_free(g_mini.line);
		draw2();
		signal(SIGINT, signal_handler);
	}
	if (signo == SIGQUIT)
	{
		// ft_listclear(&g_mini.head);
		// ft_listclear(&g_mini.env_list);
		signal(SIGQUIT, signal_handler);
	}
}

void	ft_prompt_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void	ft_proc_signal(void)
{
	signal(SIGINT, proc_signal_handler);
	signal(SIGQUIT, proc_signal_handler);
}

void	ctrl_d_checker(int c)
{
	if (c == 4)
	{
		// ft_listclear(&g_mini.head);
		if (!*g_mini.line)
		{
			ft_putstr_fd("exit", 2, 0);
			// test_print_list(g_mini.head);
			// ft_listclear(&g_mini.head);
			exit(0);
		}
	}
}
