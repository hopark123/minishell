/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:32 by hopark            #+#    #+#             */
/*   Updated: 2021/07/02 18:29:43 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"


// char	*ft_getenv(t_list *(*list), const char *varname, int varlen)
// {
// 	t_list	*env;
// 	char	*res;

// 	res = 0;
// 	env = list;
// 	while (env)
// 	{
// 		if (ft_strncmp(env->id, (char *)varname, varlen))
// 		{
// 			res = ft_strndup(env->str, ft_strlen(env->str));
// 			break ;
// 		}
// 		env = env->next;
// 	}
// 	return (res);
// }

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
	// fprintf(stderr, "bf[%s]|old[%s][%d]|new[%s]|af[%s]\n", (*list)->str, old, oldlen, new, res);
	// fprintf(stderr, "[%d][%d][%s][%d][%d]\n", ft_strlen((*list)->str), oldlen, old, ft_strlen((*list)->str) - oldlen + ft_strlen(new), ft_strlen(new));
	ft_memcpy(res, (*list)->str, old - (*list)->str);
	// fprintf(stderr, "res1[%s][%ld]\n", res, old - (*list)->str);
	ft_memcpy(res + (old - (*list)->str), new, ft_strlen(new));
	// fprintf(stderr, "res2[%s][%d]\n", res, ft_strlen(new));

	ft_memcpy(res + (old - (*list)->str) + ft_strlen(new), old + oldlen + 1, \
												ft_strlen(old + oldlen + 1));
	// fprintf(stderr, "res3[%s][%s][%d]\n", res, old + oldlen + 1,ft_strlen(old + oldlen + 1));

	res[ft_strlen((*list)->str) - oldlen + ft_strlen(new) - 1] = 0;
	// fprintf(stderr, "res4[%s][%d]\n", res, ft_strlen((*list)->str) - oldlen - 1 + ft_strlen(new));
	write(2,"{{",2);
	ft_putstr_fd((*list)->str, 2, 0);
	write(2,"}}",2);
	fprintf(stderr, "bf[%p]/|old[%s][%d]|new[%s]|af[%s]\n", (*list)->str, old, oldlen, new, res);
	ft_free((*list)->str);
	ft_free(new);
	(*list)->str = res;
	return (res);
}
// echo "$USER2$TE$AE=lol$AT"
// echo "$USER2"
// echo "$TE$"
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
			fprintf(stderr, "@bf[%p]\n",temp_l->str);
			oldlen = ft_envlen(old + 1, env_list);
			fprintf(stderr, "@2f[%s]\n",temp_l->str);
			new = ft_getenv(env_list, old + 1, oldlen);
			fprintf(stderr, "@3f[%s]\n",temp_l->str);
			ft_strswap(&temp_l, old, new, oldlen);
			fprintf(stderr, "@4f[%s]\n",temp_l->str);
		}
		else
			temp_l = temp_l->next;
		old = 0;
		write(1,"\n",1);
	}
	return (0);
}
