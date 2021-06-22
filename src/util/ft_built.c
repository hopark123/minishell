/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:09 by hopark            #+#    #+#             */
/*   Updated: 2021/06/22 20:23:07 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_built	*ft_builtndup(t_list *list)
{
	t_built		*res;

	if (!ft_malloc(&res, sizeof(t_built)))
		return (ERROR);
	res->command = list;
	res->next = 0;
	res->prev = 0;
	return (res);
}

void	ft_builtclear(t_built **built)
{
	t_built	*temp;
	t_built	*temp2;

	if (built == 0 || (*built) == 0)
		return ;
	temp2 = (*built);
	while ((*built))
	{
		if ((*built)->next)
			temp = (*built)->next;
		else
			temp = 0;
		ft_listclear(&((*built)->command));
		*built = temp;
	}
	*built = 0;
}
