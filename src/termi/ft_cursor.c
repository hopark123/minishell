/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:57:06 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/03 05:37:01 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_putchar_tc(int tc)
{
	write(STDOUT, &tc, 1);
	return (0);
}

void	ft_left_arrow(int *cursor, int *len)
{
	tputs(tgetstr("le", NULL), 1, ft_putchar_tc);
	(*cursor)--;
}

void	ft_right_arrow(int *cursor, int *len)
{
	tputs(tgetstr("nd", NULL), 1, ft_putchar_tc);
	(*cursor)++;
}

void	ft_backspace(int *cursor, int *len)
{
	tputs(tgetstr("le", NULL), 1, ft_putchar_tc);
	tputs(tgetstr("dm", NULL), 1, ft_putchar_tc);
	tputs(tgetstr("dc", NULL), 1, ft_putchar_tc);
	tputs(tgetstr("ed", NULL), 1, ft_putchar_tc);
	g_mini.line = ft_del_char(g_mini.line, *cursor);
	(*cursor)--;
	(*len)--;
}
