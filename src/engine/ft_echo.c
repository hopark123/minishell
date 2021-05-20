/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:30:43 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 12:49:16 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_echo(t_built *built)
{
	t_list	*temp_l;
	int		n_flag;

	n_flag = 0;
	temp_l = built->command;
										write(1, "*****echo{", 11);
	if (temp_l->next)
	{
		temp_l = temp_l->next;
		if (ft_strncmp(temp_l->str, "-n", 2) && temp_l->next)
		{
			temp_l = temp_l->next;
			n_flag = 1;
		}
	}
	while (temp_l)
	{
		ft_putstr_fd(temp_l->str, 1, 0);
		if (temp_l->next)
			temp_l = temp_l->next;
		else
			break ;
	}
										write(1, "}", 1);
	if (!n_flag)
		ft_putchar_fd('\n', 1, 0);
										write(1, "}\n", 3);
				//// errno 처리 필요
}
