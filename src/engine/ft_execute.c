/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:07 by suhong            #+#    #+#             */
/*   Updated: 2021/06/28 15:27:07 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static t_list	*del_pipe_col(t_built *built)
{
	if (!built->command || !built->command->next)
		return (built->command);
	if (ft_strchr("|;", built->command->str[0]))
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
	ft_del_lastblank(built);
	ft_execute2(temp, env_list, fd);
	ft_close(fd[0]);
	ft_close(fd[1]);
	dup2(tempout, STDOUT);
	dup2(tempin, STDIN);
	// ft_builtclear(&temp);
	return (1);
}
/// ./cc 2 1 3 << sa > b 


int	ft_execute2(t_built *built, t_list *env_list, int *fd)
{
	if (!built || !built->command || !built->command->str)
		return (0);
	
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
		ft_builtin(built, env_list);
	}
	return (SUCCESS);
}


