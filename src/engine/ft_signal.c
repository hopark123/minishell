/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:13:25 by hjpark            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/07/02 22:36:28 by hjpark           ###   ########.fr       */
=======
/*   Updated: 2021/07/02 22:38:58 by suhong           ###   ########.fr       */
>>>>>>> 59ce33f3981c11c2a47e8a585a1ee134c7148545
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
		signal(SIGINT, proc_signal_handler);
}


void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		tputs(tgetstr("dl", NULL), 1, ft_putchar_tc);
		draw2();
		ft_init_get_line(&g_mini.cursor, &g_mini.len);
		if (ft_strlen(g_mini.line))
			ft_free(g_mini.line);
		signal(SIGINT, signal_handler);
	}
<<<<<<< HEAD
=======
	// g_mini.status = -1;
}

void	ft_sigquit(int code)
{
	if (g_mini.pid == 0)
	{
		write(1, "\b\b", 2);
		printf("[SIGNAL] %d at %s\n", code, __func__);
		exit(128 + SIGQUIT);
	}
}

void	ft_sigterm(int code)
{
	write(1, "\b\b", 2);
	printf("[SIGNAL] %d at %s\n", code, __func__);
	exit(0);
}

void	ft_signal(void)
{
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, ft_sigquit);
	signal(SIGTERM, ft_sigterm);
>>>>>>> 59ce33f3981c11c2a47e8a585a1ee134c7148545
}

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1, 0);
		signal(SIGINT, proc_signal_handler);
	}
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1, 0);
		ft_init_get_line(&g_mini.cursor, &g_mini.len);
		if (ft_strlen(g_mini.line))
		{
			fprintf(stderr, "[%s]\n", g_mini.line);
			ft_free(g_mini.line);
		}
		draw2();
		signal(SIGINT, signal_handler);
	}
}
