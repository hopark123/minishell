/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:05:23 by hopark            #+#    #+#             */
/*   Updated: 2021/05/16 16:02:41 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list	*ft_listnew(char *str)
{
	t_list		*res;

	if (!ft_malloc(&res, sizeof(t_list)))
		return (0);
	res->str = str;
	res->next = 0;
	res->prev = 0;
	return (res);
}

void	ft_listadd_front(t_list **list, t_list **new)
{
	if ((*list) == 0 && (*new) == 0)
		return ;
	if ((*list) == 0)
	{
		(*new)->next = (*new);
		(*new)->prev = (*new);
		(*list) = (*new);
	}
	else
	{
		(*list)->prev->next = (*new);
		(*new)->prev = (*list)->prev;
		(*list)->prev = (*new);
		(*new)->next = *list;
		(*list) = (*new);
	}
}

void	ft_listadd_tail(t_list **list, t_list **new)
{
	t_list		*temp;

	if ((*list) == 0 && (*new) == 0)
		return ;
	if ((*list) == 0)
	{
		(*list) = (*new);
		(*list)->next = 0;
		(*list)->prev = 0;
	}
	else
	{
		temp = (*list);
		while (temp->next)
			temp = temp->next;
		if (temp->next)
			temp->next->prev = (*new);
		(*new)->prev = temp;
		(*new)->next = temp->next;
		temp->next = (*new);
	}
}

void	ft_listdelone(t_list **list)
{
	if ((*list) == 0)
		return ;
	if ((*list)->next)
		(*list)->next->prev = 0;
	if ((*list)->prev)
		(*list)->prev->next = 0;
	ft_free(*list);
	(*list) = 0;
}

void	ft_listclear(t_list **list)
{
	t_list	*temp;
	t_list	*temp2;

	if (list == 0 || (*list) == 0)
		return ;
	temp2 = (*list);
	while ((*list))
	{
		if ((*list)->next)
			temp = (*list)->next;
		else
			temp = 0;
		ft_listdelone(list);
		*list = temp;
	}
	*list = 0;
}