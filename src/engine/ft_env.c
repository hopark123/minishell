/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:40:10 by suhong            #+#    #+#             */
/*   Updated: 2021/06/30 18:08:59 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_env(t_built *built, t_list *env_list)
{
	if (!built)
		return (ERROR);
	if (built->command->next)
	{
		printf("we need no arg\n");
		return (ERROR);
	}
	ft_show_env_list(env_list);
	return (SUCCESS);
}
