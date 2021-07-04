/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:09:30 by suhong            #+#    #+#             */
/*   Updated: 2021/07/04 21:23:44 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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

static int	get_list_size(t_list *list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int	print_sorted_env_list(t_list *env_list)
{
	t_list	*dup;
	t_list	*node_1;
	t_list	*node_2;
	int		i;

	write(2, "printin\n", 8);
	i = 0;
	dup = ft_listdup(env_list);
	if (!dup)
		write(2, "@@\n", 3);
	while (i < get_list_size(dup))
	{
		node_1 = dup;
		node_2 = node_1->next;
		while (node_2)
		{
			if (ft_strncmp3(node_1->id, node_2->id, ft_strlen(node_1->id)) > 0)
				swap_node(node_1, node_2);
			node_1 = node_1->next;
			node_2 = node_2->next;
		}
		i++;
	}
	write(2, "%%\n", 3);
	ft_show_env_list_2(dup, "declare -x ");
	ft_listclear(&dup);
	return (SUCCESS);
}

static char	**split_equal(char *str)
{
	char	**tmp;
	char	*spot;

	tmp = (char **)malloc(sizeof(char *) * 3);
	if (!tmp)
		ft_error("malloc error");
	spot = ft_strchr(str, '=');
	if (spot)
	{
		tmp[0] = ft_strndup(str, spot - str);
		tmp[1] = ft_strndup(spot + 1, ft_strlen(spot + 1));
		if (!tmp[0] || !tmp[1])
			ft_error("malloc error");
	}
	else
	{
		tmp[0] = ft_strndup(str, ft_strlen(str));
		if (!tmp[0])
			ft_error("malloc error");
		tmp[1] = 0;
	}
	tmp[2] = 0;
	return (tmp);
}

int	ft_export(t_built *built, t_list **env_list)
{
	t_list	*order;
	char	**tmp;

	if (!built->command->next)
		return (print_sorted_env_list(*env_list));
	if (!ft_strncmp(built->command->next->str, " ", 1))
	{
		return (ERROR);
	}
	order = built->command->next->next;
	if (!order || !order->str)
	{
		return (ERROR);
	}
	tmp = split_equal(order->str);
	if (!tmp)
		return (ERROR);
	return (ft_add_env_list(env_list, tmp[0], tmp[1]));
}
