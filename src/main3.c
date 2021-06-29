#include "head.h"

int	nbr_length(int n)
{
	int	i = 0;

	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	get_cursor_position(int *col, int *rows)
{
	int		a = 0;
	int		i = 1;
	char	buf[255];
	int		ret;
	int		temp;

	write(0, "\033[6n", 4);  //report cursor location
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	while (buf[i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			if (a == 0)
				*rows = atoi(&buf[i]) - 1;
			else
			{
				temp = atoi(&buf[i]);
				*col = temp - 1;
			}
			a++;
			i += nbr_length(temp) - 1;
		}
		i++;
	}
}

int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	move_cursor_left(int *col, int *row, char *cm)
{
	if (*col == 0)
		return ;
	--(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);

}

void	move_cursor_right(int *col, int *row, char *cm)
{
	++(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);

}

void	delete_end(int *col, int *row, char *cm, char *ce)
{
	if (*col != 0)
		--(*col);
	tputs(tgoto(cm, *col, *row), 1, putchar_tc);
	tputs(ce, 1, putchar_tc);
}


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
		ft_get_line();
		if (g_mini.line)
		{
			// add_history(line);
			// rl_replace_line("", 0);
			// rl_redisplay();
			built = ft_parse(g_mini.line, env_list);
			status = ft_start(built, env_list);
		}
	}
}



int	main(int argc, char **argv, char **envp)
{
	t_list	*env_list;

	env_list = ft_init_env_list(envp);
	// draw();

	ft_init_term();
	loop(env_list);
	ft_listclear(&env_list);
	return (0);
}