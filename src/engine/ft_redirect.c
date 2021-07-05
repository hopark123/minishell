/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:02:01 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 03:30:54 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static int	redirect1_1(t_built *built, int temp, int *fd)
{
	char	*line;
	int		len;

	if (temp < 0)
	{
		ft_perror(built->command->next->next->str, "No such file or directory");
		return (ERROR);
	}
	dup2(temp, fd[1]);
	ft_close(temp);
	fd[1] = temp;
	if (!built->prev)
	{
		while (1)
		{
			len = get_next_line(fd[0], &line);
			ft_putstr_fd(line, fd[1], 0);
			ft_putstr_fd("\n", fd[1], 0);
			if (len >= 0)
				ft_free(line);
			if (len <= 0)
				break ;
		}
	}
	return (SUCCESS);
}

int	ft_redirect(t_built *built, char *type, int *fd)
{
	t_list	*list;
	int		temp;

	temp = -1;
	list = built->command;
	if (!list->next || !list->next->next)
	{
		g_mini.status = ERROR_INVALID_ARGUMENT;
		ft_syntaxerror('>');
		return (ERROR_INVALID_ARGUMENT);
	}
	list = list->next->next;
	if (ft_strncmp(type, "TRUNC", 5))
		temp = open(list->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else if (ft_strncmp(type, "APPEND", 6))
		temp = open(list->str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	return (redirect1_1(built, temp, fd));
}

int	ft_redirect2(t_built *built)
{
	t_list	*list;
	int		temp;

	if (ft_guard_next(built, 2) == ERROR)
	{
		ft_syntaxerror('<');
		return (ERROR);
	}
	list = built->command->next->next;
	temp = open(list->str, O_RDONLY, S_IRWXU);
	if (temp < 0)
	{
		ft_perror(list->str, "No such file or directory");
		return (ERROR);
	}
	dup2(temp, g_mini.pip[0]);
	ft_close(temp);
	return (SUCCESS);
}

int	ft_redirect3(t_built *built, int *fd)
{
	t_list	*list;
	char	*line;
	int		temp;

	temp = 0;
	if (pipe(g_mini.pip) < 0)
		ft_error("ft_redirect3: pipe error");
	if (ft_guard_next(built, 2) == ERROR)
		return (ERROR);
	list = built->command->next->next;
	while (get_next_line(fd[0], &line) >= 0)
	{
		if (ft_strncmp(line, list->str, ft_strlen(list->str)))
		{
			ft_close(g_mini.pip[1]);
			ft_free(line);
			return (SUCCESS);
		}
		ft_putstr_fd(line, g_mini.pip[1], 0);
		ft_putstr_fd("\n", g_mini.pip[1], 0);
		ft_free(line);
	}
	return (SUCCESS);
}
