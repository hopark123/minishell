/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:15:41 by hjpark            #+#    #+#             */
/*   Updated: 2021/06/29 20:27:48 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_get_line(void)
{
	int		n;
	char	*c;
	char	*tmp;

	if (!ft_malloc(&g_mini.line, sizeof(char)))
		return ;
	if (!ft_malloc(&c, sizeof(char)))
		return ;
	g_mini.line[0] = 0;
	c[0] = 0;
	while (read(STDIN, &n, sizeof(int)) > 0)
	{
		// ft_putnbr_fd(n, STDERR, 0);
		c[0] = n;
		tmp = ft_strjoin(g_mini.line, c);
		ft_free(g_mini.line);
		g_mini.line = tmp;
		ft_putstr_fd(c, STDOUT, "\x1b[35m");
		if(ft_strchr("\n", *c))
			break ;
	}
	g_mini.line[ft_strchr(g_mini.line, '\n') - g_mini.line] = 0;
}
