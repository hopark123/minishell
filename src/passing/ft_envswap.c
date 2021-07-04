/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:32 by hopark            #+#    #+#             */
/*   Updated: 2021/07/04 21:29:18 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_isenv(char c)
{
	if (ft_isdigit(c) || ft_isalpha(c) || c == '_')
		return (SUCCESS);
	return (ERROR);
}

static int	ft_envlen(char *str, t_list *env_list)
{
	int		i;

	i = 0;
	if (ft_isdigit((int)str[i]))
		return (1);
	i++;
	while (str[i])
	{
		if (ft_strchr("$ ><|;\'\"=", str[i]) || ft_isenv(str[i]) == ERROR)
			return (i);
		i++;
	}
	// if (ft_getenv(env_list, str, i + 1)
			// return (i + 1);
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

static void	jump_s_quotes(char *str, int *i)
{
	if (str[*i] == '\'')
	{
		(*i)++;
		while (str[*i] && str[*i] != '\'')
			(*i)++;
	}
}

void	ft_envswap(t_list *list, t_list *env_list)
{
	int		i;
	char	*old;
	char	oldlen;
	char	*new;

	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			jump_s_quotes(list->str, &i);
			old = ft_strchr(&(list->str[i]), '$');
			if (old)
			{
				oldlen = ft_envlen(old + 1, env_list);
				new = ft_getenv(env_list, old + 1, oldlen);
				ft_strswap(&list, old, new, oldlen);
			}
			else
				break ;
		}
		list = list->next;
	}
}
