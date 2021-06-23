/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:30:43 by hopark            #+#    #+#             */
/*   Updated: 2021/06/23 15:02:33 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_exit(t_built *built)
{
	t_list	*list;

	list = built->command;
	if (!list->next)
	{
		ft_putstr_fd("exit\n", 1, "\x1b[34m");
		exit(0);
	}
	else if (list->next && !list->next->next)
	{
		if (ft_is_num(list->next->str))
			exit(ft_atoi(list->next->str));
		else
		{
			ft_putstr_fd("bash: exit: ", 1, "\x1b[31m");
			ft_putstr_fd(list->next->str, 1, "\x1b[31m");
			ft_putstr_fd(": numeric argument required\n", 1, "\x1b[31m");
		}
	}
	else
	{
		ft_putstr_fd("exit\nbash: exit: too many arguments\n", 1, "\x1b[31m" );
	}
	return (ERROR);
}

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}