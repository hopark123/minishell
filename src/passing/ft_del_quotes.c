/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:43:00 by hopark            #+#    #+#             */
/*   Updated: 2021/07/02 20:13:27 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_del_quotes(t_built *built)
{
	t_list	*temp_l;
	char	*new;
	char	*id;

	temp_l = built->command;
	new = 0;
	while (temp_l)
	{
		if (*(temp_l->str) == '\'' || *(temp_l->str) == '\"')
		{
			new = ft_strndup(temp_l->str + 1, ft_strlen(temp_l->str + 1) - 1);
			id = ft_strndup("quotes", 7);
			ft_free(temp_l->str);
			temp_l->str = new;
			temp_l->id = id;
		}
		temp_l = temp_l->next;
	}
	return (SUCCESS);
}
