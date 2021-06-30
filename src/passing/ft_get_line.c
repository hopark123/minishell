/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:15:41 by hjpark            #+#    #+#             */
/*   Updated: 2021/06/30 17:15:29 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	ft_putchar_tc(int tc)
{
	write(STDOUT, &tc, 1);
	return (0);
}

void	get_cursor_pt(int *col, int *row)
{
	int		a;
	int		i;
	char	buf[255];
	int		ret;
	int		temp;

	write(0, "\033[6n", 4);
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	a = 0;
	i = 1;
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			if (a == 0)
				*row = ft_atoi(&buf[i]) - 1;
			else
			{
				temp = ft_atoi(&buf[i]);
				*col = temp - 1;
			}
			a++;
			i += ft_num_len(temp) - 1;
		}
		i++;
	}
}

void	ft_get_line(void)
{
	int		n;
	char	c;
	char	*tmp;
	int		len;
	int		cursor;
	int		col;
	int		row;

	if (!ft_malloc(&g_mini.line, sizeof(char)))
		return ;
	g_mini.line[0] = 0;
	len = 0;
	cursor = 0;
	while (read(STDIN, &n, sizeof(int)) > 0)
	{
		if (n == LEFT_ARROW && cursor > 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar_tc);
			cursor--;
		}
		else if (n == RIGHT_ARROW && cursor < len)
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar_tc);
			cursor++;
		}
		else if (n == BACKSPACE && cursor > 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar_tc);
			tputs(tgetstr("dm", NULL), 1, ft_putchar_tc);
			tputs(tgetstr("dc", NULL), 1, ft_putchar_tc);
			tputs(tgetstr("ed", NULL), 1, ft_putchar_tc);
			g_mini.line = ft_del_char(g_mini.line, cursor);
			cursor--;
			len--;
		}
		else if (ft_isprint(n))
		{
			tputs(tgetstr("im", NULL), 1, ft_putchar_tc);
			tputs(tgetstr("ic", NULL), 1, ft_putchar_tc);
			cursor++;
			len++;
			ft_putchar_fd((char)n, STDOUT, "\x1b[34m");
			tputs(tgetstr("ip", NULL), 1, ft_putchar_tc);
			tputs(tgetstr("ei", NULL), 1, ft_putchar_tc);
			g_mini.line = ft_add_char(g_mini.line, (char)n, cursor);
		}
		else if (n == '\n')
		{
			ft_putchar_fd((char)n, STDOUT, "\x1b[34m");
			n = 0;
			break ;
		}
		n = 0;
	}
}
