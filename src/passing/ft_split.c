/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:00:11 by hopark            #+#    #+#             */
/*   Updated: 2021/05/17 15:12:28 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	ft_wordlen(char const *s, char c, int *flag)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (ft_strchr("<>;|", s[i]))
	{
		len++;
		i++;
		if (ft_strchr(">", s[i]))
			len++;
		return (len);
	}
	if (*flag == 1)
		while (s[i] && s[i] != c)
		{
			if (s[i] == '"' || ft_strchr("<>;|", s[i]))
			{
				break;
			}
			i++;
			len++;
		}
	else if ((*flag) == -1)
	{
		i++;
		len++;
		while (s[i] && s[i] != '"')
		{
			i++;
			len++;
		}
		*flag = 1;
		len++;
	}
	else if ((*flag) == -2)
	{
		i++;
		len++;
		while (s[i] && s[i] != '\'')
		{
			i++;
			len++;
		}
		*flag = 1;
		len++;
	}
	return (len);
}

t_list	*ft_split(const char *str, const char c)
{
	t_list		*temp;
	t_list		*head;
	char		*res;
	int			len;
	int	flag;

	flag = 1;
	head = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (((*str) && (*str) == c))
		{
			str++;
		}
		if (*str == '"' )
			flag = -1;
		else if (*str == '\'')
			flag = -2;
		len = ft_wordlen(str, c, &flag);
		res = ft_strndup(str, len);
		temp = ft_listnew(res);
		ft_listadd_tail(&head, &temp);
		str += len;
	}
	return (head);
}

t_built	*ft_builtnup(t_list *list)
{
	t_built		*res;

	if (!ft_malloc(&res, sizeof(t_built)))
		return (ERROR);
	res->command = list;
	return (res);
}

int		ft_split_built(t_built *built)
{
	t_list		*temp_l;
	t_built		*temp_b;
	t_built		*new_b;

	if (!built || !built->command)
		return (ERROR);
	temp_b = built;
	temp_l = built->command;
	while (temp_l->next)
	{
		if (ft_strchr("<>;|", *(temp_l->str)))
		{
			if (!(temp_l->next))
				return (ERROR);
			new_b = ft_builtnup(temp_l);
			temp_b->next = new_b;
			new_b->prev = temp_b;
			temp_l->prev->next = 0;
			temp_b = new_b;
		}
		temp_l = temp_l->next;
	}
	return (SUCCESS);
}

