/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:31:22 by suhong            #+#    #+#             */
/*   Updated: 2021/05/17 13:46:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

static int	remember_quo(char c)
{
	static int	q_info = 0;

	if (ft_strchr("\"'", c))
	{
		if (!q_info)
			q_info = c;
		else if (q_info == c)
		{
			q_info = 0;
			return (1);
		}
	}
	return (q_info);
}

//char	*meet_word(char *str, t_string *string)
int	meet_word(char *str)
{
	char	*start;
	char	*tmp;
	size_t	i;
	int	flag;
	//int	old_flag;

	tmp = 0;
	i = 0;
	start = str;
	flag = 0;
	//old_flag = 0;
	while (str[i])
	{
		//연속된 공백 넘어가기
		while (str[i] == ' ' && !flag)
			start = &str[++i];
		flag = remember_quo(str[i]);
		i++;
		//if (flag != old_flag || (str[i] == ' ' && !flag) || str[i] == '\0')
		if ((str[i] == ' ' && !flag) || str[i] == '\0')
		{
			tmp = ft_substr(start, 0, &str[i] - start);
			if (!tmp)
				return (ERROR);
			//연결 리스트에 tmp 추가
			printf("%s\n", tmp);
			free(tmp);
			start = &str[i];
		}
		//old_flag = flag;
	}
	return (1);
}
