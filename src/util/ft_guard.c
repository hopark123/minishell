/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_guard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:06 by hopark            #+#    #+#             */
/*   Updated: 2021/06/23 18:24:07 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_guard_next(t_built *built, int n)
{
	t_list	*temp;

	temp = built->command;
	while (n--)
	{
		if (temp->next)
			temp = temp->next;
		else
			return (ERROR);
	}
	return (SUCCESS);
}
