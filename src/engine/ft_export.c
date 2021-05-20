/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:09:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/20 12:49:04 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	list_size(t_list *list)
{
	t_list	*i;
	int		size;

	i = list;
	size = 0;
	while (i)
	{
		size++;
		i = i->next;
	}
	return (size);
}

static t_list	*init_node_point(t_list **node_1, t_list **node_2, t_list *start)
{
	t_list	*index;

	index = start;
	while (index->prev)
		index = index->prev;
	*node_1 = index;
	*node_2 = index->next;
	return (index);
}

t_list	*sort_env_list(t_list *env_list)
{
	t_list	*node_1;
	t_list	*node_2;
	t_list	*tmp;
	t_list	*start;
	int	i;

	i = list_size(env_list);
	start = env_list;
	while (i--)
	{
		start = init_node_point(&node_1, &node_2, start);
		while (node_2)
		{
			if (ft_strncmp3(node_1->id, node_2->id, ft_strlen(node_1->id)) < 0)
			{
				tmp = node_1;
				node_1 = node_2;
				node_2 = tmp;
				node_1->prev = tmp->prev;
				node_2->prev = node_1;
				node_2->next = node_1->next;
				node_1->next = tmp->next;
			}
			node_1 = node_1->next;
			node_2 = node_2->next;
		}
	}
	return (init_node_point(&node_1, &node_2, start));
}

int	ft_export(t_list *command, t_list *env_list)
{
	char	*str;
	char	**tmp;

	if (!command)
		return (0);
	str = command->str;
	if (!str)
		return (0);
	if (!ft_strchr(str, '=') || str[0] == '=')
	{
		if (command->next->str)
			printf("export: '%s': not a valid identifier\n", command->next->str);
		free(str);
		return (0);
	}
	tmp = ft_split(str, '=');
	free(str);
	if (!tmp)
		return (0);
	if (command->next && command->next->str)
		if (tmp[1] == 0 && !ft_strncmp2(command->next->str, " ", 2))
			return (ft_add_env_list(&env_list, tmp[0], command->next->str));
	return (ft_add_env_list(&env_list, tmp[0], tmp[1]));
}
