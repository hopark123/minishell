/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:59:46 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/05 02:57:40 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "passing.h"

void	ft_del_quotes(t_list *list)
{
	int			i;
	char		c;
	int			temp;

	while (list)
	{
		i = 0;
		while (list->str && list->str[i])
		{
			if (ft_strchr("\'\"", list->str[i]))
			{
				c = list->str[i];
				list->str = ft_del_char(list->str, i + 1);
				temp = ft_strchr(&list->str[i], c) - list->str;
				list->str = ft_del_char(list->str, temp + 1);
				i = temp;
			}
			else
				i++;
		}
		list = list->next;
	}
}
