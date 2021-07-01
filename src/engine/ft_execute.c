/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:07 by suhong            #+#    #+#             */
/*   Updated: 2021/07/01 20:59:59 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static t_list	*del_pipe_col(t_built *built)
{
	t_built	*temp;

	if (!built->command || !built->command->next)
	{
		if (ft_strchr("|;", built->command->str[0]) && !built->command->next)
		{
			temp = built->next;
			ft_builtdelone(&built);
			if (temp)
				return (temp->command);
			else
				return (0);
		}
		return (built->command);
	}
	if (ft_strchr("|;", built->command->str[0]))
		return (built->command->next->next);
	return (built->command);
}

int	ft_execute(t_built *built, t_list *env_list)
{
	t_built	*temp;
	t_list	*list;
	int		fd[2];
	int		tempout;
	int		tempin;
	int		status;

	if (!built || !built->command || !built->command->str)
		return (EXIT_SUCCESS);
	tempin = dup(STDIN);
	tempout = dup(STDOUT);
	fd[0] = STDIN;
	fd[1] = STDOUT;
	if (!(list = del_pipe_col(built)))
		return (REDIRECTION_ERROR);
	temp = ft_builtndup(list);
	ft_split_built(temp, "><");
	ft_del_lastblank(built);
	g_mini.pip[0] = dup(STDIN);
	g_mini.pip[1] = dup(STDOUT);
	status = ft_execute2(temp, env_list, fd);
	ft_close(fd[0]);
	ft_close(fd[1]);
	dup2(tempout, STDOUT);
	dup2(tempin, STDIN);
	// ft_builtclear(&temp);
	return (status);
}


int	ft_execute2(t_built *built, t_list *env_list, int *fd)
{
	int	res;

	if (!built || !built->command || !built->command->str)
		return (EXIT_SUCCESS);
	// test_print_passing(built);
	if (built->next)
	{
		res = ft_execute2(built->next, env_list, fd);
		if (res == ERROR)
			return (res);
	}
	if (ft_strncmp(built->command->str, ">", 1))
		res = ft_redirect(built, "TRUNC", fd);
	else if (ft_strncmp(built->command->str, ">>", 2))
		res = ft_redirect(built, "APPEND", fd);
	else if (ft_strncmp(built->command->str, "<", 1))
		res = ft_redirect2(built, fd);
	else if (ft_strncmp(built->command->str, "<<", 2))
		res = ft_redirect3(built, fd);
	else
		res = ft_builtin(built, env_list);
	return (res);
}
