/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:08:30 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 19:44:15 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	ft_distinguish(t_list *list)
{
	int		flag1;
	int		flag2;

	flag1 = 1;
	flag2 = 1;
	if (list->prev->id && ft_strncmp(list->prev->id, "quotes", 6))
		flag1 = -1;
	if (list->id && ft_strncmp(list->id, "quotes", 6))
		flag2 = -1;
	return (flag1 * flag2);
}

void	ft_del_blank(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;

	temp_l = built->command;
	while (temp_l)
	{
		temp_l2 = temp_l->next;
		if (ft_strlen(temp_l->str) == 0)
		{
			if (temp_l->prev && ft_strlen(temp_l->prev->str) == 0 \
										&& ft_distinguish(temp_l) == 1)
			{
				temp_l2 = temp_l->next;
				ft_listdelone(&temp_l);
			}
			else if (!(temp_l->prev))
			{
				temp_l2 = temp_l->next;
				ft_putstr_fd(temp_l->str, 1, 0);
				built->command = temp_l2;
				ft_listdelone(&temp_l);
			}
		}
		temp_l = temp_l2;
	}
}

void	ft_del_blank2(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;

	temp_l = built->command;
	while (temp_l)
	{
		temp_l2 = temp_l->next;
		if (ft_strlen(temp_l->str) == 0 && ft_strncmp(temp_l->id, "quotes", 6))
			ft_listdelone(&temp_l);
		temp_l = temp_l2;
	}
}
