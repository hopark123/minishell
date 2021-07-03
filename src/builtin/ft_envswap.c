/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:32 by hopark            #+#    #+#             */
/*   Updated: 2021/07/03 18:21:19 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	ft_envlen(char *str, t_list *env_list)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_getenv(env_list, str, i + 1))
			return (i + 1);
		if (ft_strchr("$ ><|;\'\"=", str[i]))
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_strswap(t_list **list, char *old, char *new, int oldlen)
{
	char	*res;

	if (!ft_malloc(&res, sizeof(char) * (ft_strlen((*list)->str) \
									- oldlen + ft_strlen(new))))
		return (0);
	ft_memcpy(res, (*list)->str, old - (*list)->str);
	ft_memcpy(res + (old - (*list)->str), new, ft_strlen(new));
	ft_memcpy(res + (old - (*list)->str) + ft_strlen(new), old + oldlen + 1, \
												ft_strlen(old + oldlen + 1));
	res[ft_strlen((*list)->str) - oldlen + ft_strlen(new) - 1] = 0;
	ft_free((*list)->str);
	ft_free(new);
	(*list)->str = res;
	return (res);
}

int	*ft_envswap(t_built *built, t_list *env_list)
{
	t_list	*temp_l;
	char	*old;
	char	oldlen;
	char	*new;

	temp_l = built->command;
	while (temp_l)
	{
		if (*(temp_l->str) != '\'')
			old = ft_strchr(temp_l->str, '$');
		if (old)
		{
			oldlen = ft_envlen(old + 1, env_list);
			new = ft_getenv(env_list, old + 1, oldlen);
			ft_strswap(&temp_l, old, new, oldlen);
		}
		else
			temp_l = temp_l->next;
		old = 0;
	}
	return (0);
}
