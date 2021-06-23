/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:02:01 by hjpark            #+#    #+#             */
/*   Updated: 2021/06/23 16:19:40 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_redirect(t_built *built, char *type, int *fd)
{
	t_list	*list;

	fd[0] = fd[1];
	list = built->command;
	if (!list->next || !list->next->next)
		return (ERROR);
	list = list->next->next;
	if (ft_strncmp(type, "TRUNC", 5))
		fd[1] = open(list->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else if (ft_strncmp(type, "APPEND", 6))
		fd[1] = open(list->str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	dup2(fd[1], fd[0]);
	ft_close(fd[1]);
	return (SUCCESS);
}

int	ft_redirect2(t_built *built, int *fd)
{
	t_list	*list;

	fd[1] = fd[0];
	if (!ft_guard_next(built, 2))
		return (ERROR);
	list = built->command->next->next;
	fd[0] = open(list->str, O_RDONLY, S_IRWXU);
	dup2(fd[0], fd[1]);
	return (SUCCESS);
}

int	ft_redirect3(t_built *built, int *fd)
{
	t_list	*list;
	char	*line;

	fd[1] = fd[0];
	if (!ft_guard_next(built, 2))
		return (ERROR);
	list = built->command->next->next;
	if (get_next_line(fd[1], &line) >= 0)
	{
		ft_putstr_fd(line, fd[0], 0);
		if (ft_strncmp(line, list->str, ft_strlen(list->str)))
		{
			write(1,"@@@@@@@@@\n",1);
			return (SUCCESS);
		}
	}
	return (SUCCESS);
}
