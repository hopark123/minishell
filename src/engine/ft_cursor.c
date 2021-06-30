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