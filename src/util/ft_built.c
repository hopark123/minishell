/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:09 by hopark            #+#    #+#             */
/*   Updated: 2021/05/19 14:10:28 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_built	*ft_builtnup(t_list *list)
{
	t_built		*res;

	if (!ft_malloc(&res, sizeof(t_built)))
		return (ERROR);
	res->command = list;
	res->next = 0;
	res->prev = 0;
	return (res);
}
