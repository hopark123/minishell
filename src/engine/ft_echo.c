/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:30:43 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 21:12:49 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_echo(t_built *built)
{
	t_list	*list;
	int		n_flag;

	n_flag = 0;
	list = built->command;
										write(1, "*****echo{", 11);
	if (ft_strncmp(list->next->str, " ", 1))
	{
		list = list->next->next;
		if (ft_strncmp(list->str, "-n", 2) && list->next)
		{
			list = list->next;
			n_flag = 1;
		}
		while (list)
		{
			ft_putstr_fd(list->str, 1, 0);
			if (list->next)
				list = list->next;
			else
				break ;
		}
	}
										write(1, "}", 1);
	if (!n_flag)
		ft_putchar_fd('\n', 1, 0);
										write(1, "}\n", 3);
				//// errno 처리 필요
	return (1);
}
