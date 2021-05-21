/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:16 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 21:18:28 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	ft_quotes(char const *s, int *i, int *flag, char c)
{
	(*i)++;
	while (s[(*i)] && s[(*i)] != c)
		(*i)++;
	(*flag) = 1;
	(*i)++;
}

static int	ft_wordlen(char const *s, char c, int *flag)
{
	int			i;

	i = 0;
	if (ft_strchr("<>;|.", s[i]))
	{
		i++;
		if (ft_strchr(">", s[i]))
			i++;
		return (i);
	}
	if (*flag == 1)
	{
		while (s[i] && s[i] != c)
		{
			if (s[i] == '"' || s[i] == '\'' || ft_strchr("<>;|", s[i]))
				break ;
			i++;
		}
	}
	else if ((*flag) == -1)
		ft_quotes(s, &i, flag, '"');
	else if ((*flag) == -2)
		ft_quotes(s, &i, flag, '\'');
	return (i);
}

t_list	*ft_split2(const char *str, const char c)
{
	t_list		*temp;
	t_list		*head;
	char		*res;
	int			len;
	int			flag;

	flag = 1;
	head = 0;
	if (!str || !(*str))
		return (0);
	while (*str)
	{
		len = 0;
		while (((*str) && (*str) == c))
		{
			str++;
			len++;
		}
		if (len)
		{
			res = ft_strndup(" ", 1);
			temp = ft_listnew(res, 0);
			ft_listadd_tail(&head, &temp);
		}
		else
		{
			if (*str == '"')
				flag = -1;
			else if (*str == '\'')
				flag = -2;
			len = ft_wordlen(str, c, &flag);
			res = ft_strndup(str, len);
			temp = ft_listnew(res, 0);
			ft_listadd_tail(&head, &temp);
			str += len;
		}
	}
	return (head);
}
