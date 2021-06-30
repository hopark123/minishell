/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:30:43 by hopark            #+#    #+#             */
/*   Updated: 2021/06/30 17:43:30 by suhong           ###   ########.fr       */
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
	list = list->next;
	if (list->next && !list->next->next)
	{
		if (ft_is_num(list->next->str))
			exit(ft_atoi(list->next->str));
		else
		{
			ft_putstr_fd("minish: exit: ", STDERR, "\x1b[31m");
			ft_putstr_fd(list->next->str, STDERR, "\x1b[31m");
			ft_putstr_fd(": numeric argument required\n", STDERR, "\x1b[31m");
		}
	}
	else
		ft_putstr_fd("exit\nminish: exit: too many arguments\n", STDERR, "\x1b[31m" );
	return (EXIT_FAILURE);
}

int	ft_close(int fd)
{
	if (fd > 1)
		return (close(fd));
	return (1);
}
