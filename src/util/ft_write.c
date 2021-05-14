/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:07:08 by hopark            #+#    #+#             */
/*   Updated: 2021/05/14 15:10:59 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_putchar_fd(char c, int fd, char *color)
{
	write(1, color, 6);
	write(fd, &c, 1);
	write(1, "\x1b[0m", 5);
}

void	ft_putstr_fd(char *s, int fd, char *color)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (i < ft_strlen(s))
	{
		ft_putchar_fd(s[i], fd, color);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd, char *color)
{
	unsigned int	n2;

	if (n < 0)
	{
		ft_putchar_fd('-', fd, color);
		n2 = (unsigned int)n * (-1);
	}
	else
		n2 = (unsigned int)n;
	if (n2 >= 10)
		ft_putnbr_fd((int)(n2 / 10), fd, color);
	ft_putchar_fd((int)(n2 % 10 + '0'), fd, color);
}
