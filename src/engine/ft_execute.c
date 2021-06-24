/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:07 by suhong            #+#    #+#             */
/*   Updated: 2021/06/24 17:21:08 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static t_list	*del_pipe_col(t_built *built)
{
	if (ft_strncmp(built->command->str, "|", ft_strlen(built->command->str)))
		return (built->command->next->next);
	else if (ft_strncmp(built->command->str, ";", ft_strlen(built->command->str)))
		return (built->command->next->next);
	return (built->command);
}

int	ft_execute(t_built *built, t_list *env_list)
{
	t_built	*temp;
	int		fd[2];
	int		tempout;
	int		tempin;

	if (!built || !built->command || !built->command->str)
		return (1);
	tempin = dup(STDIN);
	tempout = dup(STDOUT);
	fd[0] = STDIN;
	fd[1] = STDOUT;
	temp = ft_builtndup(del_pipe_col(built));
	ft_split_built(temp, "><");
	ft_execute2(temp, env_list, fd);
	ft_close(fd[0]);
	ft_close(fd[1]);
	dup2(tempout, 1);
	dup2(tempin, 0);
	// ft_builtclear(&temp);
	return (1);
}

int	ft_execute2(t_built *built, t_list *env_list, int *fd)
{
	if (!built || !built->command || !built->command->str)
		return (0);
	ft_del_lastblank(built);
	// test_print_passing(built);
	if (built->next)
		ft_execute2(built->next, env_list, fd);
	if (ft_strncmp(built->command->str, ">", 1))
		ft_redirect(built, "TRUNC", fd);
	else if (ft_strncmp(built->command->str, ">>", 2))
		ft_redirect(built, "APPEND", fd);
	else if (ft_strncmp(built->command->str, "<", 1))
		ft_redirect2(built, fd);
	else if (ft_strncmp(built->command->str, "<<", 2))
		ft_redirect3(built, fd);
	else
	{
		// char *line2;
		// printf("[%d]\n", fd[1]);
		// get_next_line(fd[1], &line2);
		ft_builtin(built, env_list);
	}
	return (SUCCESS);
}


