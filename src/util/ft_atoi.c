/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:26:12 by hopark            #+#    #+#             */
/*   Updated: 2021/06/30 20:52:10 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_sign(int sign)
{
	if (sign > 0)
		return (-1);
	else
		return (0);
}

int	ft_is_num(const char *nptr)
{
	int			i;
	int			num;
	int			temp;
	int			sign;

	i = 0;
	num = 0;
	temp = 0;
	sign = 1;
	if (!nptr)
		return (ERROR);
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (ft_isdigit(nptr[i]))
	{
		temp = num;
		num = num * 10 + nptr[i] - '0';
		i++;
		if ((sign != -1 && num < 0) || (temp > num && num != INT_MIN))
			return (ERROR);
	}
	if (nptr[i] != 0)
		return (ERROR);
	return (SUCCESS);
}

int	ft_atoi(const char *nptr)
{
	int				num;
	int				sign;
	int				i;
	int				cnt;

	i = 0;
	sign = 1;
	num = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	cnt = i;
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	if (nptr[i] != 0)
		return (ERROR);
	return (num * sign);
}
