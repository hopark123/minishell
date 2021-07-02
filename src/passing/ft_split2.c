/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:16 by hopark            #+#    #+#             */
/*   Updated: 2021/07/02 21:07:41 by hjpark           ###   ########.fr       */
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

static void	ft_split2_2(t_list *head, const char *str, int len, const char c)
{
	// char	*res;
	// if (len)
	// {
	// 	res = ft_strndup(" ", 1);
	// 	temp = ft_listnew(res, 0);
	// 	ft_listadd_tail(&head, &temp);
	// }
	// else
	// {
	// 	if (str[i] == '"')
	// 		flag = -1;
	// 	else if (str[i] == '\'')
	// 		flag = -2;
	// 	len = ft_wordlen(str, c, &flag);
	// 	res = ft_strndup(str, len);
	// 	temp = ft_listnew(res, 0);
	// 	ft_listadd_tail(&head, &temp);
	// 	str += len;
	// }
}

t_list	*ft_split2(char *str, char c)
{
	t_list		*temp;
	t_list		*head;
	char		*res;
	int			len;
	int			flag;
	int			i;

	flag = 1;
	head = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		len = 0;
		while (str[i] && (str[i]) == c)
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
			if (str[i] == '"')
				flag = -1;
			else if (str[i] == '\'')
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
