/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:26 by hopark            #+#    #+#             */
/*   Updated: 2021/05/19 21:23:00 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_parsing(t_built *temp_b, t_list *env_list)
{
	int		res;

	if (ft_strncmp(temp_b->command->str, "echo", 4))
		res = ft_echo(temp_b);
	else if (ft_strncmp(temp_b->command->str, "cd", 2))
		res = ft_cd(temp_b, env_list);
	else if (ft_strncmp(temp_b->command->str, "pwd", 3))
		res = ft_pwd(temp_b);
	//else if (ft_strncmp(temp_b->command->str, "export", 6))
	//	res = ft_export()
	//else if (ft_strncmp(temp_b->command->str, "unset", 5))
	//	res = ft_unset()
	//else if (ft_strncmp(temp_b->command->str, "env", 3))
	//	res = ft_env()
	//else if (ft_strncmp(temp_b->command->str, "exit", 4))
	//	res = ft_exit()
	//else if (ft_strchr("><|;",(temp_b->command->str)))
	//	res = ft_parsing2()
	//else
	return (res);
}


//// 글자수도 체크해줘야함!!!