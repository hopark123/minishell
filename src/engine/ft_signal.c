/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:13:25 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/02 22:38:58 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_sigint(int code)
{
	fprintf(stderr, "[%d]\n", g_mini.pid);
	if (g_mini.pid == 0)
	{
		write(1, "\b\b", 2);
		printf("[SIGNAL] %d at %s\n", code, __func__);
		tputs(tgetstr("dl", NULL), 1, ft_putchar_tc);
		draw2();
		exit(128 + SIGINT);
	}
	else
	{
		ft_init_get_line(&g_mini.cursor, &g_mini.len);
		if (ft_strlen(g_mini.line))
		{
			fprintf(stderr, "[%s]\n", g_mini.line);
			ft_free(g_mini.line);
		}
	}
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
