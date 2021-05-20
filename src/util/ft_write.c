/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:07:08 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 12:40:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_putchar_fd(char c, int fd, char *color)
{
	int		res;

	res = write(1, color, 6);
	res = write(fd, &c, 1);
	if (res == -1)
		return (-1);
	res = write(1, "\x1b[0m", 5);
	return (1);
}

int	ft_putstr_fd(char *s, int fd, char *color)
{
	int		i;

	i = 0;
	if (!s)
		return (-1);
	while (i < ft_strlen(s))
	{
		if (ft_putchar_fd(s[i], fd, color) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd, char *color)
{
	unsigned int	n2;
	static int		i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd, color);
		n2 = (unsigned int)n * (-1);
	}
	else
		n2 = (unsigned int)n;
	if (n2 >= 10)
		ft_putnbr_fd((int)(n2 / 10), fd, color);
	i += ft_putchar_fd((int)(n2 % 10 + '0'), fd, color);
	return (i);
}
