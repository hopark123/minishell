/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:24:08 by hopark            #+#    #+#             */
/*   Updated: 2021/05/21 15:53:31 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*ft_getenv(t_list *list, const char *varname, int varlen)
{
	t_list	*env;
	char	*res;

	res = 0;
	env = list;
	while (env)
	{
		if (ft_strncmp(env->id, (char *)varname, varlen))
		{
			res = ft_strndup(env->str, ft_strlen(env->str));
			break ;
		}
		env = env->next;
	}
	return (res);
}
