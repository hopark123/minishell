/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:55:34 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/02 21:22:34 by suhong           ###   ########.fr       */
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

static int	face_space_at_start_case(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strchr("><;|", str[i]))
	{
		g_mini.status = ERROR_INVALID_ARGUMENT;
		ft_perror(&str[i], "syntax error");
		return (ERROR_INVALID_ARGUMENT);
	}
	return (SUCCESS);
}

static int	face_normal_char(char *str, int *i, int *flag)
{
	char	find;

	if (str[*i] && ft_strchr("><;|", str[*i]))
	{
		find = str[*i];
		i++;
		while (str[*i] == ' ')
			(*i)++;
		if (!str[*i] && ((find == ';' && *i == 0) || ft_strchr("><|", find)))
		{
			g_mini.status = ERROR_INVALID_ARGUMENT;
			ft_free(str);
			return (ERROR_INVALID_ARGUMENT);
		}
		(*i)++;
		if (str[*i] == '"')
			*flag = -1;
		else if (str[*i] == '\'')
			*flag = -2;
	}
	return (SUCCESS);
}

int	ft_check_syntax(char *str)
{
	int		i;
	int		flag;
	int		res;

	flag = 1;
	if (face_space_at_start_case(str) != SUCCESS)
		return (ERROR_INVALID_ARGUMENT);
	i = 0;
	while (str[i])
	{
		if (flag == 1)
			if (face_normal_char(str, &i, &flag) != SUCCESS)
				return (ERROR_INVALID_ARGUMENT);
		if (flag == -1 && str[i] == '"')
			ft_quotes(str, &i, &flag, '"');
		else if (flag == -2 && str[i] == '\'')
			ft_quotes(str, &i, &flag, '\'');
		i++;
	}
	return (SUCCESS);
}
