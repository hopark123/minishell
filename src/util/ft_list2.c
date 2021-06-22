/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:01 by hopark            #+#    #+#             */
/*   Updated: 2021/06/22 22:25:32 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	**ft_listtochar(t_list *list)
{
	char	**res;
	char	*str;
	int		i;
	int		n;
	t_list	*temp;

	n = 0;
	temp = list;
	while (temp)
	{
		temp = temp->next;
		n++;
	}
	if (!ft_malloc(&res, sizeof(char *) * (n + 1)))
		return (ERROR);
	i = 0;
	while (i < n)
	{
		if (list->id)
		{
			str = ft_strjoin(list->id, "=");
			res[i] = ft_strjoin(str, list->str);
		}
		else
			res[i] = ft_strndup(list->str, ft_strlen(list->str));
		list = list->next;
		i++;
	}
	res[i] = 0;
	return (res);
}
