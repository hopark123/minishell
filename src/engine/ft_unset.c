/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:20:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/21 14:04:30 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_2.h"

int	ft_unset(t_built *built, t_list *env_list)
{
	t_list	*i;

	if (!ft_strncmp2(built->command->next->str, " ", 1))
		return (ERROR);
	i = built->command->next->next;
	while (i)
	{
		if (!ft_strncmp2(i->str, " ", 1))
			ft_delenv(env_list, i->str);
		i = i->next;
	}
	return (1);
}
