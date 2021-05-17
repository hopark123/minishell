/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:00:11 by hopark            #+#    #+#             */
/*   Updated: 2021/05/16 16:20:38 by hopark           ###   ########.fr       */
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

// int		ft_split_str(t_built **built,t_list **list)
// {
	
// }

// void	ft_split_built(t_built *built)
// {
// 	t_list		*temp_l;
// 	t_built		*temp_b;

// 	if (!built || !built->command)
// 		return ;
// 	temp_b = built;
// 	temp_l = built->command;
// 	while (temp_l->next)
// 	{
// 		if (ft_strchr("<>;|", *(temp_l->str)))
// 			ft_split_str(&temp_b, &temp_l);
// 		else
// 			temp_l = temp_l->next;
// 	}

// }


