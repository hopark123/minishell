/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:30:43 by hopark            #+#    #+#             */
/*   Updated: 2021/07/06 06:48:06 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	*arraytostr(char ***array)
{
	int		i;
	char	*res;
	char	*temp;

	i = 0;
	if (!ft_malloc(&res, sizeof(char) * 1))
		return (0);
	while ((*array)[i])
	{
		temp = res;
		res = ft_strjoin(temp, (*array)[i]);
		ft_free(temp);
		ft_free((*array)[i]);
		i++;
	}
	ft_free((*array));
	(*array) = 0;
	return (res);
}

static t_built	*resplit(t_built *built)
{
	t_list		*list;
	t_built		*temp_b;
	char		**temp_a;
	char		*temp_s;

	list = built->command;
	temp_a = ft_listtochar(list);
	temp_s = arraytostr(&temp_a);
	list = ft_token_split(temp_s);
	temp_b = ft_builtndup(list);
	ft_put_blank(temp_b);
	return (temp_b);
}

int	ft_echo(t_built *built)
{
	t_built	*re_built;
	t_list	*list;
	int		n_flag;

	n_flag = 0;
	re_built = resplit(built);
	list = re_built->command;
	if (list->next && ft_strncmp(list->next->str, " ", 1))
	{
		list = list->next->next;
		while (ft_strncmp2(list->str, "-", 1) && list->next)
		{
			if (ft_strncmp(list->str, "-n", 2))
				n_flag = 1;
			list = list->next->next;
		}
		while (list)
		{
			ft_putstr_fd(list->str, STDOUT, 0);
			list = list->next;
		}
	}
	if (!n_flag)
		ft_putchar_fd('\n', 1, 0);
	ft_builtclear(&re_built);
	return (SUCCESS);
}
