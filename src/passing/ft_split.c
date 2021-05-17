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

static int	ft_wordlen(char const *s, char c)
{
	int			i;
	int			len;
	int			flag;

	i = 0;
	len = 0;
	flag = 1;
	while (s[i] && (s[i] != c || flag == -1))
	{
		if (s[i] == '"')
		{
			while (s[i] != '"')
			{
				i++;
				len++;
			}
			flag *= -1;
		}
		i++;
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

	head = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (((*str) && (*str) == c))
		{
			str++;
		}
		len = ft_wordlen(str, c);
		res = ft_strndup(str, len);
		temp = ft_listnew(res);
		ft_listadd_tail(&head, &temp);
		str += len;
	}
	return (head);
}
