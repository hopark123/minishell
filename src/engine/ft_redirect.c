/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:02:01 by hjpark            #+#    #+#             */
/*   Updated: 2021/06/24 15:50:08 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_redirect(t_built *built, char *type, int *fd)
{
	t_list	*list;
	int		temp;

	list = built->command;
	if (!list->next || !list->next->next)
		return (ERROR);
	list = list->next->next;
	if (ft_strncmp(type, "TRUNC", 5))
		temp = open(list->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else if (ft_strncmp(type, "APPEND", 6))
		temp = open(list->str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	dup2(temp, fd[1]);
	ft_close(temp);
	fd[1] = temp;
	return (SUCCESS);
}

int	ft_redirect2(t_built *built, int *fd)
{
	t_list	*list;
	int		temp;

	if (!ft_guard_next(built, 2))
		return (ERROR);
	list = built->command->next->next;
	temp = open(list->str, O_RDONLY, S_IRWXU);
	dup2(temp, fd[0]);
	ft_close(temp);
	fd[0] = temp;
	return (SUCCESS);
}

int	ft_redirect3(t_built *built, int *fd)
{
	t_list	*list;
	char	*line;
	int		temp;

	if (!ft_guard_next(built, 2))
		return (ERROR);
	list = built->command->next->next;
	while (get_next_line(fd[0], &line) >= 0)
	{
		if (ft_strncmp(line, list->str, ft_strlen(list->str)))
		{
			ft_exit(built);
			return (SUCCESS);
		}
	}
	return (SUCCESS);
}
