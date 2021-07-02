/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:16 by hopark            #+#    #+#             */
/*   Updated: 2021/07/02 23:38:39 by suhong           ###   ########.fr       */
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
	if (ft_strchr("<>;|", s[i]))
	{
		i++;
		if (ft_strchr("><", s[i]))
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

static t_list	*ft_split2_1(char *str, int *i, int len, char c)
{
	t_list	*temp_l;
	char	*temp_s;
	int		flag;

	flag = 1;
	if (len)
	{
		temp_s = ft_strndup(" ", 1);
		temp_l = ft_listnew(temp_s, 0);
	}
	else
	{
		if (str[(*i)] == '"')
			flag = -1;
		else if (str[(*i)] == '\'')
			flag = -2;
		len = ft_wordlen(&str[(*i)], c, &flag);
		temp_s = ft_strndup(&str[(*i)], len);
		temp_l = ft_listnew(temp_s, 0);
		(*i) += len;
	}
	return (temp_l);
}

t_list	*ft_split2(char *str, char c)
{
	t_list		*temp;
	t_list		*head;
	int			len;
	int			flag;
	int			i;

	i = 0;
	flag = 1;
	head = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		len = 0;
		while (str[i] && (str[i]) == c)
		{
			i++;
			len++;
		}
		temp = ft_split2_1(str, &i, len, c);
		ft_listadd_tail(&head, &temp);
	}
	return (head);
}
