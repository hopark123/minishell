/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:26 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 13:28:33 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_parsing(t_built *built, t_list *env_list)
{
	int		res;

	if (!built || !built->command)
		return (0);
	if (ft_strncmp(built->command->str, "echo", 4))
		res = ft_echo(built);
	else if (ft_strncmp(built->command->str, "cd", 2))
		res = ft_cd(built, env_list);
	else if (ft_strncmp(built->command->str, "pwd", 3))
		res = ft_pwd(built);
	//else if (ft_strncmp(built->command->str, "export", 6))
	//	res = ft_export()
	//else if (ft_strncmp(built->command->str, "unset", 5))
	//	res = ft_unset()
	//else if (ft_strncmp(built->command->str, "env", 3))
	//	res = ft_env()
	//else if (ft_strncmp(built->command->str, "exit", 4))
	//	res = ft_exit()
	//else if (ft_strchr("><|;",(built->command->str)))
	//	res = ft_parsing2()
	//else
}


//// 글자수도 체크해줘야함!!!