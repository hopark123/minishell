/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongseonghyeon <hongseonghyeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:01 by hopark            #+#    #+#             */
/*   Updated: 2021/07/05 17:13:47 by hongseonghy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list	*ft_listnew(char *str, char *id)
{
	t_list		*res;

	if (!ft_malloc(&res, sizeof(t_list)))
		ft_error("malloc error");
	res->str = str;
	res->id = id;
	res->next = 0;
	res->prev = 0;
	return (res);
}

t_list	*ft_listnew2(char *str, char *id)
{
	t_list		*res;

	if (!ft_malloc(&res, sizeof(t_list)))
		ft_error("malloc error");
	res->str = str;
	res->id = id;
	res->next = 0;
	res->prev = 0;
	return (res);
}

void	ft_listadd_back(t_list **list, t_list **new)
{
	if ((*new) == 0)
		return ;
	if ((*list))
	{
		(*list) = (*new);
		(*list)->next = (*list);
		(*list)->prev = (*list);
	}
	else
	{
		if ((*list)->next)
			(*list)->next->prev = (*new);
		(*new)->prev = (*list);
		(*new)->next = (*list)->next;
		(*list)->next = (*new);
	}
}

void	ft_listadd_tail(t_list **list, t_list **new)
{
	t_list		*temp;

	if ((*new) == 0)
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
	temp = (*list);
	while (temp)
		temp = temp->next;
}

void	ft_listdelone(t_list **list)
{
	if (list == 0 || (*list) == 0)
		return ;
	if ((*list)->next)
		(*list)->next->prev = (*list)->prev;
	if ((*list)->prev)
		(*list)->prev->next = (*list)->next;
	if ((*list)->id)
		ft_free((*list)->id);
	if ((*list)->str)
		ft_free((*list)->str);
	ft_free(*list);
	// (*list) = 0;
}
