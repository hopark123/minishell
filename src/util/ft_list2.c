/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:01 by hopark            #+#    #+#             */
/*   Updated: 2021/07/03 17:54:04 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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

char	**ft_env_listtochar(t_list *list)
{
	char	**res;
	char	*str;
	int		i;
	int		n;

	n = ft_list_cnt(list);
	if (!ft_malloc(&res, sizeof(char *) * (n + 1)))
		return (0);
	i = 0;
	while (i < n)
	{
		str = ft_strjoin(list->id, "=");
		res[i] = ft_strjoin(str, list->str);
		ft_free(str);
		list = list->next;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_listtochar(t_list *list)
{
	char	**res;
	int		i;
	int		n;
	t_list	*temp;

	n = 0;
	temp = list;
	while (temp)
	{
		temp = temp->next;
		n++;
	}
	if (!ft_malloc(&res, sizeof(char *) * (n + 1)))
		return (0);
	i = 0;
	while (i < n)
	{
		res[i] = ft_strndup(list->str, ft_strlen(list->str));
		list = list->next;
		i++;
	}
	res[i] = 0;
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

t_list	*ft_listdup(t_list *list)
{
	t_list	*copy;
	t_list	*dup;
	t_list	*add;

	dup = list;
	copy = 0;
	while (dup)
	{
		add = ft_listnew2(ft_strndup(dup->str, ft_strlen(dup->str)), \
			ft_strndup(dup->id, ft_strlen(dup->id)));
		if (!add)
			ft_error("malloc error");
		ft_listadd_tail(&copy, &add);
		dup = dup->next;
	}
	return (copy);
}
