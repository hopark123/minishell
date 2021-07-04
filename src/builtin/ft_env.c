/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:40:10 by suhong            #+#    #+#             */
/*   Updated: 2021/07/04 22:57:59 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_env(t_built *built, t_list *env_list)
{
	if (!built)
		return (ERROR);
	if (built->command->next)
	{
		printf("we need no arg\n");
		return (ERROR);
	}
	ft_show_env_list(env_list, 0);
	return (SUCCESS);
}
