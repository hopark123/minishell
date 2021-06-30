/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:02:01 by hjpark            #+#    #+#             */
/*   Updated: 2021/06/30 19:39:30 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_redirect(t_built *built, char *type, int *fd)
{
	t_list	*list;
	int		temp;

	list = built->command;
	if (!list->next || !list->next->next)
		return (REDIRECTION_ERROR);
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
		return (REDIRECTION_ERROR);
	list = built->command->next->next;
	temp = open(list->str, O_RDONLY, S_IRWXU);
	dup2(temp, g_mini.pip[0]);
	ft_close(temp);
	return (SUCCESS);
}

int	ft_redirect3(t_built *built, int *fd)
{
	t_list	*list;
	char	*line;
	int		temp;
	int		heredoc[2];

	if (pipe(g_mini.pip) < 0)
		ft_error("ft_redirect3: pipe error");
	if (!ft_guard_next(built, 2))
		return (REDIRECTION_ERROR);
	list = built->command->next->next;
	ft_putstr_fd("start\n", 2, 0);
	while (get_next_line(fd[0], &line) >= 0)
	{
		if (ft_strncmp(line, list->str, ft_strlen(list->str)))
		{
			ft_close(g_mini.pip[1]);
			ft_free(line);
			return (SUCCESS);
		}
		else
		{
			ft_putstr_fd(line, g_mini.pip[1], 0);
			ft_putstr_fd("\n", g_mini.pip[1], 0);
			ft_free(line);
		}
	}
	return (SUCCESS);
}
