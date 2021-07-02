/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:55:34 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/02 21:13:26 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	ft_quotes(char const *s, int *i, int *flag, char c)
{
	(*i)++;
	while (s[(*i)] && s[(*i)] != c)
		(*i)++;
	(*flag) = 1;
}

int	ft_check_syntax(char *str)
{
	int		i;
	int		flag;
	int		res;
	char	find;

	flag = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strchr("><;|", str[i]))
		return (128);
	i = 0;
	while (str[i])
	{
		if (flag == 1)
		{
			if (str[i] && ft_strchr("><;|", str[i]))
			{
				find = str[i];
				i++;
				while (str[i] == ' ')
					i++;
				if (!str[i] && ((find == ';' && i == 0) || ft_strchr("><|", find)))
				{
					g_mini.status = 128;
					ft_free(str);
					return (128);
				}
				i++;
			}
			if (str[i] == '"')
				flag = -1;
			else if (str[i] == '\'')
				flag = -2;
		}
		if (flag == -1 && str[i] == '"')
			ft_quotes(str, &i, &flag, '"');
		else if (flag == -2 && str[i] == '\'')
			ft_quotes(str, &i, &flag, '\'');
		i++;
	}
	return (SUCCESS);
}