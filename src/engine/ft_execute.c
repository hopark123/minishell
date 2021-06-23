/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:07 by suhong            #+#    #+#             */
/*   Updated: 2021/06/23 18:58:17 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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
	temp = ft_builtndup(built->command);
	ft_split_built(temp, "><");
	ft_execute2(temp, env_list, fd);
	printf("end\n");
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
	test_print_passing(built);
	printf("{%s}\n", built->command->str);
	write(1,"{",1);
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
		ft_builtin(built, env_list);
	write(1,"}",1);
	printf("@{%s}\n", built->command->str);
	return (SUCCESS);
}


