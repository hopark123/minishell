/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:09:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/20 18:56:16 by suhong           ###   ########.fr       */
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

static void	swap_node(t_list *node_1, t_list *node_2)
{
	char	*tmp;


	tmp = node_1->str;
	node_1->str = node_2->str;
	node_2->str = tmp;
	tmp = node_1->id;
	node_1->id = node_2->id;
	node_2->id = tmp;
}

static int	print_sorted_env_list(t_list *env_list)
{
	t_list	*node_1;
	t_list	*node_2;
	char	*tmp;
	int	i;

	i = list_size(env_list);
	while (i--)
	{
		node_1 = env_list;
		node_2 = node_1->next;
		while (node_2)
		{
			if (ft_strncmp3(node_1->id, node_2->id, ft_strlen(node_1->id)) > 0)
				swap_node(node_1, node_2);
			node_1 = node_1->next;
			node_2 = node_2->next;
		}
	}
	ft_show_env_list (env_list);
	return (1);
}

int	ft_export(t_built *built, t_list *env_list)
{
	t_list	*order;
	char	**tmp;

	if (!built->command->next)
		return (print_sorted_env_list(env_list));
	if (!ft_strncmp(built->command->next->str, " ", 2))
		return (ERROR);
	write(1, "in\n", 3);
	order = built->command->next->next;
	if (!order->str)
		return (ERROR);
	if (!ft_strchr(order->str, '=') || order->str[0] == '=')
	{
		if (order->next && order->next->next)
			printf("export: '%s': not a valid identifier\n", order->next->next->str);
		return (ERROR);
	}
	tmp = ft_split(order->str, '=');
	if (!tmp)
		return (ERROR);
	return (ft_add_env_list(&env_list, tmp[0], tmp[1]));
}
