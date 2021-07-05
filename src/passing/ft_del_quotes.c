/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:59:46 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/05 22:37:35 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "passing.h"

void	ft_del_quotes(t_list *list)
{
	int			i;
	char		c;
	int			temp;

	temp = 0;
	while (list)
	{
		i = 0;
		while (list->str && list->str[i])
		{
			if (ft_strncmp(list->str, "\"\"", 2) || ft_strncmp(list->str, "\'\'", 2))
			{
				ft_free(list->str);
				list->str = 0;
				break ;
			}
			if (ft_strchr("\'\"", list->str[i]))
			{
				c = list->str[i];
				fprintf(stderr,"[%s][%s][%c][%d][%d]\n", list->str, &list->str[i], c, i, temp);
				list->str = ft_del_char(&list->str, i + 1);
				fprintf(stderr,"[%s][%s][%c][%d][%d]\n", list->str, &list->str[i], c, i, temp);
				temp = ft_strchr(&list->str[i], c) - list->str;
				fprintf(stderr,"[%s][%s][%c][%d][%d]\n", list->str, &list->str[i], c, i, temp);
				list->str = ft_del_char(&list->str, temp + 1);
				i = temp;
			}
			else
				i++;
		}
		list = list->next;
	}
}
