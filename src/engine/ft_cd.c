/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:06:01 by hopark            #+#    #+#             */
/*   Updated: 2021/07/02 19:34:26 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	fd_cd2(t_list *env_list, char *dest, char *temp, int flag)
{
	int	res;

	res = chdir(dest);
	ft_free(temp);
	free(dest);
	return (res);
}

int	ft_cd(t_built *built, t_list *env_list)
{
	t_list	*list;
	char	*temp;
	char	*dest;
	int		flag;

	flag = 1;
	if (built->command->next && built->command->next->next)
	{
		list = built->command->next->next;
		if (*(list->str) == '/')
			temp = 0;
		else if (*(list->str) == '~')
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
		dest = ft_strjoin(temp, list->str);
	else
	{
		temp = ft_getenv(env_list, "HOME", 4);
		dest = ft_strndup(temp, ft_strlen(temp));
	}
}
