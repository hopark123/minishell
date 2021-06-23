/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:02:01 by hjpark            #+#    #+#             */
/*   Updated: 2021/06/23 18:59:17 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_redirect(t_built *built, char *type, int *fd)
{
	t_list	*list;

	list = built->command;
	ft_close(fd[0]);
	fd[0] = fd[1];
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

	ft_close(fd[0]);
	fd[0] = fd[1];
	if (!ft_guard_next(built, 2))
		return (ERROR);
	list = built->command->next->next;
	fd[0] = open(list->str, O_RDONLY, S_IRWXU);
	dup2(fd[0], STDIN);
	ft_close(fd[0]);
	return (SUCCESS);
}

int	ft_redirect3(t_built *built, int *fd)
{
	t_list	*list;
	char	*line;

	ft_close(fd[0]);
	fd[0] = fd[1];
	if (!ft_guard_next(built, 2))
		return (ERROR);
	list = built->command->next->next;
	while (get_next_line(STDIN, &line) >= 0)
	{
		if (ft_strncmp(line, list->str, ft_strlen(list->str)))
		{
			return (SUCCESS);
		}
	}
	return (SUCCESS);
}
