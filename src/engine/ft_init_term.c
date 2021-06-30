/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:17:04 by hjpark            #+#    #+#             */
/*   Updated: 2021/06/30 17:56:34 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_init_term(void)
{
	char			*env;

	env = getenv("TERM");
	if (env == NULL)
		env = "xterm";
	if (tgetent(NULL, env) < 1)
		return ;
	tcgetattr(STDIN, &g_mini.backup);
	tcgetattr(STDIN, &g_mini.term);
	g_mini.term.c_lflag &= ~ICANON;
	g_mini.term.c_lflag &= ~ECHO;
	g_mini.term.c_cc[VMIN] = 1;
	g_mini.term.c_cc[VTIME] = 0;
	tcsetattr(STDIN, TCSANOW, &g_mini.term);
	ft_init_termcap();
}

void	ft_reset_term(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &g_mini.backup);
}

void	ft_init_termcap(void)
{
	g_mini.cm = tgetstr("g_mini.cm", NULL);
	g_mini.ce = tgetstr("g_mini.ce", NULL);
}
