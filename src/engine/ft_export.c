/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:09:30 by suhong            #+#    #+#             */
/*   Updated: 2021/05/19 12:48:04 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_export(t_list *command, t_list *env_list)
{
	char	*str;
	char	**tmp;

	if (!command)
		return (0);
	str = ft_strndup(command->str, ft_strlen(command->str));
	if (!str)
		return (0);
	if (!ft_strchr(str, '=') || str[0] == '=')
	{
		printf("export: '%s': not a valid identifier\n", command->str);
		free(str);
		return (0);
	}
	tmp = ft_split(str, '=');
	free(str);
	if (!tmp)
		return (0);
	return (ft_add_env_list(&env_list, tmp[0], tmp[1]));
}
