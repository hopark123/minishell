/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_built.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:23 by hopark            #+#    #+#             */
/*   Updated: 2021/07/04 17:33:05 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_split_built(t_built *built, char *str)
{
	t_list		*temp_l;
	t_built		*temp_b;
	t_built		*new_b;

	if (!built || !built->command)
		return (ERROR);
	temp_b = built;
	temp_l = built->command;
	while (temp_l)
	{
		if (*(temp_l->str) && ft_strchr(str, *(temp_l->str)))
		{
			new_b = ft_builtndup(temp_l);
			temp_b->next = new_b;
			new_b->prev = temp_b;
			if (temp_l->prev)
				temp_l->prev->next = 0;
			temp_b = new_b;
		}
		temp_l = temp_l->next;
	}
	return (SUCCESS);
}
