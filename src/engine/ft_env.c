/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:40:10 by suhong            #+#    #+#             */
/*   Updated: 2021/05/20 17:05:55 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_2.h"

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
	return (1);
}
