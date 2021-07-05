/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongseonghyeon <hongseonghyeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:09 by hopark            #+#    #+#             */
/*   Updated: 2021/07/05 17:43:02 by hongseonghy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_built	*ft_builtndup(t_list *list)
{
	t_built		*res;

	if (!list)
		return (0);
	if (!ft_malloc(&res, sizeof(t_built)))
		return (0);
	res->command = list;
	res->next = 0;
	res->prev = 0;
	return (res);
}
void	ft_builtonlyclear(t_built **built)
{
	t_built	*temp;

	if (built == 0 || (*built) == 0)
		return ;
	int i = 0;
	while ((*built))
	{
		if ((*built)->next)
			temp = (*built)->next;
		else
			temp = 0;
		fprintf(stderr, "o_b[%d]\n", i++);
		ft_free(*built);
		*built = temp;
	}
}

void	ft_builtclear(t_built **built)
{
	t_built	*temp;
	t_built	*temp2;

	if (built == 0 || (*built) == 0)
		return ;
	temp2 = (*built);
	while ((*built))
	{
		if ((*built)->next)
			temp = (*built)->next;
		else
			temp = 0;
		ft_listclear(&((*built)->command));
		ft_free(*built);
		*built = temp;
	}
}


void	ft_builtdelone(t_built **built)
{
	if ((*built) == 0)
		return ;
	if ((*built)->next)
		(*built)->next->prev = (*built)->prev;
	if ((*built)->prev)
		(*built)->prev->next = (*built)->next;
	ft_listclear(&((*built)->command));
	(*built) = 0;
}

int	ft_built_cnt(t_built *built)
{
	t_built	*temp;
	int		i;

	i = 0;
	temp = built;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
