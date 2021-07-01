/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:55:34 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/01 16:57:42 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
void	ft_quotes(char const *s, int *i, int *flag, char c)
{
	(*i)++;
	while (s[(*i)] && s[(*i)] != c)
		(*i)++;
	(*flag) = 1;
	(*i)++;
}
int	ft_check_syntax(char *str)
{
	int		i;
	int		flag;
	int		res;

	flag = 0;
	i = 0;
	while (str[i])
	{

	}
}