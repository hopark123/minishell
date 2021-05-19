/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_built.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:23 by hopark            #+#    #+#             */
/*   Updated: 2021/05/19 17:47:36 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_split_built(t_built *built)
{
	t_list		*temp_l;
	t_built		*temp_b;
	t_built		*new_b;

	if (!built || !built->command)
		return (ERROR);
	temp_b = built;
	temp_l = built->command;
	while (temp_l->next)
	{
		if (*(temp_l->str) && ft_strchr("<>;|", *(temp_l->str)))
		{
			if (!(temp_l->next))
				return (ERROR);
			new_b = ft_builtnup(temp_l);
			temp_b->next = new_b;
			new_b->prev = temp_b;
			temp_l->prev->next = 0;
			temp_b = new_b;
		}
		temp_l = temp_l->next;
	}
	return (SUCCESS);
}
