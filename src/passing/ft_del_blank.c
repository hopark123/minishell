/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongseonghyeon <hongseonghyeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:08:30 by hopark            #+#    #+#             */
/*   Updated: 2021/07/05 16:37:33 by hongseonghy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "passing.h"

void	ft_del_lastblank(t_built *built)
{
	t_list	*temp_l;

	fprintf(stderr, "lastin\n");
	if (!built || !built->command)
		return ;
	temp_l = built->command;
	fprintf(stderr, "while before\n");
	while (temp_l)
	{
	fprintf(stderr, "while in\n");
		fprintf(stderr, "while in2\n");
		// fprintf(stderr, "now[%p], next[%p]\n", temp_l, temp_l->next);
		fprintf(stderr, "now[%p]\n", temp_l);
		fprintf(stderr, "out[%p]\n", temp_l->next);
		if (ft_strncmp(temp_l->str, " ", 1) && !(temp_l->next))
		{
			fprintf(stderr, "now[%p], next[%p]\n", temp_l, temp_l->next);
			ft_listdelone(&temp_l);
			return ;
		}
	fprintf(stderr, "while out\n");
		temp_l = temp_l->next;
	}
	// while (temp_l->next)
	// {
	// 	temp_l = temp_l->next;
	// }
	// if (ft_strncmp(temp_l->str, " ", 1))
	// 	ft_listdelone(&temp_l);
}

void	ft_del_blank(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;

	if (!built)
		return ;
	temp_l = built->command;
	while (temp_l)
	{
		temp_l2 = temp_l->next;
		if (temp_l->str && !ft_strlen(temp_l->str))
		// if (ft_strlen(temp_l->str) == 0)
			ft_listdelone(&temp_l);
		temp_l = temp_l2;
	}
}

void	ft_del_blank2(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;

	if (built)
		return ;
	temp_l = built->command;
	while (temp_l)
	{
		temp_l2 = temp_l->next;
		if (ft_strncmp(temp_l->str, " ", 1))
			ft_listdelone(&temp_l);
		temp_l = temp_l2;
	}
}
