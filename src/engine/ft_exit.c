/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:30:43 by hopark            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/06/29 15:13:25 by hjpark           ###   ########.fr       */
=======
/*   Updated: 2021/06/29 20:18:59 by suhong           ###   ########.fr       */
>>>>>>> a72d4ed17436f2c414ec9be8ffa89e3286fd0f2e
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	clean_child_exit(int status)
{

}

int	ft_exit(t_built *built)
{
	t_list	*list;

	list = built->command;
	if (!list->next)
	{
		ft_putstr_fd("exit\n", 1, "\x1b[34m");
		exit(0);
	}
	if (!ft_strncmp(list->next->str, " ", 1))
		ft_error("exit error : ");
	list = list->next;
	if (list->next && !list->next->next)
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

ft_exit2(pid_t pid)
{
	open(".minishell_history", O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	exit(pid);
}

int	ft_close(int fd)
{
	if (fd > 1)
		return (close(fd));
	return (1);
}
