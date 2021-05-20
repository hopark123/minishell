/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:35 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 17:16:41 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list	*ft_init_env_list(char **envp)
{
	size_t	i;
	char	**env_str;
	t_list	*tmp;
	t_list	*list;

	list = 0;
	i = 0;
	while (envp[i])
	{
		env_str = ft_split(envp[i], '=');
		if (!env_str)
			return (0);
		if (!env_str[1])
			env_str[1] = ft_strndup("", 1);
		tmp = ft_listnew(env_str[1], env_str[0]);
		if (!tmp)
		{
			ft_listclear(&list);
			return (0);
		}
		ft_listadd_tail(&list, &tmp);
		i++;
	}
	return (list);
}

int	ft_add_env_list(t_list **list, char *id, char *str)
{
	t_list	*tmp;

	if (!id)
		return (0);
	if (!str)
		str = ft_strndup("", 1);
	if (!str)
		return (0);
	ft_delenv(*list, id);
	tmp = ft_listnew(str, id);
	if (!tmp)
	{
		free(id);
		free(str);
		return (0);
	}
	ft_listadd_tail(list, &tmp);
	return (1);
}

char	*ft_delenv(t_list *list, char *str)
{
	char	*tmp;

	while (list)
	{
		if (ft_strncmp(list->id, str, ft_strlen(str)))
		{
			tmp = list->str;
			ft_listdelone(&list);
			return (tmp);
		}
		list = list->next;
	}
	return (0);
}

void	ft_show_env_list(t_list *list)
{
	while (list)
	{
		ft_putstr_fd(list->id, 1, 0);
		write(1, "=", 1);
		ft_putstr_fd(list->str, 1, 0);
		write(1, "\n", 1);
		list = list->next;
	}
}
