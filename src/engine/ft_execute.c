/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:07 by suhong            #+#    #+#             */
/*   Updated: 2021/06/21 18:32:11 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_execute(t_built *built, t_list *env_list)
{
	t_built *temp;

	temp = ft_builtndup(built->command);
	ft_split_built(temp, "><");
	ft_del_blank(temp);
	ft_del_blank2(temp);
	ft_listjoin(temp);
	ft_builtin(temp, env_list);
	return (1);
}
