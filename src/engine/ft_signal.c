/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:13:25 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/02 22:36:28 by hjpark           ###   ########.fr       */
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
}
