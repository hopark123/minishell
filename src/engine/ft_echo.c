/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:30:43 by hopark            #+#    #+#             */
/*   Updated: 2021/07/01 15:16:49 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_echo(t_built *built)
{
	t_list	*list;
	int		n_flag;

	n_flag = 0;
	list = built->command;
	if (list->next && ft_strncmp(list->next->str, " ", 1))
	{
		list = list->next->next;
		while (ft_strncmp2(list->str, "-", 1) && list->next)
		{
			if (ft_strncmp(list->str, "-n", 2))
				n_flag = 1;
			list = list->next->next;
		}
		while (list)
		{
			ft_putstr_fd(list->str, STDOUT, 0);
			if (list->next)
				list = list->next;
			else
				break ;
		}
	}
	if (!n_flag)
		ft_putchar_fd('\n', 1, 0);
	return (SUCCESS);
}
