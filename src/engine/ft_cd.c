/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:06:01 by hopark            #+#    #+#             */
/*   Updated: 2021/06/21 17:31:15 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_cd(t_built *built, t_list *env_list)
{
	t_list	*list;
	char	*temp;
	char	*dest;
	int		res;
	int		flag;

	flag = 1;
	if (built->command->next->next)
	{
		list = built->command->next->next;
		if (*(list->str) == '/' && flag)
			temp = 0;
		else if (*(list->str) == '~' || !flag)
			flag = 0;
		else
		{
			temp = getcwd(0, BUFFER_SIZE);
			dest = ft_strjoin(temp, "/");
			ft_free(temp);
			temp = dest;
		}
	}
	else
		flag = 0;
	if (flag)
	{
		dest = ft_strjoin(temp, list->str);
		ft_free(temp);
		ft_free(list->str);
	}
	else
	{
		temp = ft_getenv(env_list, "HOME", 4);
		dest = ft_strndup(temp, ft_strlen(temp));
	}
	res = chdir(dest);
	write(1, "{",1);
	ft_putstr_fd(dest, 1, 0);
	write(1, "}\n",2);
	free(dest);
	return (res);
}
