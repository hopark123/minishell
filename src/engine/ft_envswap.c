/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:32 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 19:22:15 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	ft_envlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
		if (ft_strchr("$ ><|;\"", str[i]))
			return (i);
	}
	return (i);
}

static char	*ft_strswap(t_list *list, char *old, char *new, int oldlen)
{
	char	*res;

	if (!ft_malloc(&res, sizeof(ft_strlen(list->str) \
									- oldlen + ft_strlen(new))))
		return (0);
	ft_memcpy(res, list->str, old - list->str);
	ft_memcpy(res + (old - list->str), new, ft_strlen(new));
	ft_memcpy(res + (old - list->str) + ft_strlen(new), old + oldlen + 1, \
												ft_strlen(old + oldlen));
	res[ft_strlen(list->str) - oldlen + ft_strlen(new)] = 0;
	ft_free(list->str);
	ft_free(new);
	return (res);
}

int	*ft_envswap(t_built *built, t_list *env_list)
{
	t_list	*temp_l;
	char	*old;
	char	oldlen;
	char	*new;
	int		i;

	temp_l = built->command;
	while (temp_l)
	{
		i = 0;
		while ((temp_l->str)[i])
		{
			if ((temp_l->str)[i] == '\'')
			{
				i++;
				while ((temp_l->str)[i] != '\'')
					i++;
				i++;
			}
			else if ((temp_l->str)[i] == '$')
			{
				oldlen = ft_envlen(&(temp_l->str)[i + 1]);
				new = ft_getenv(env_list, &(temp_l->str)[i + 1], oldlen);
				temp_l->str = ft_strswap(temp_l, &(temp_l->str)[i], new, oldlen);
				i += ft_strlen(new);
			}
			else
				i++;
		}
		temp_l = temp_l->next;
	}
	return (0);
}
