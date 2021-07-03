/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:06:01 by hopark            #+#    #+#             */
/*   Updated: 2021/07/02 19:57:03 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static char	*ft_make_str(t_built *built, int *flag)
{
	char	*prev;
	char	*temp;
	t_list	*list;

	list = built->command->next->next;
	if (*(list->str) == '/')
	{
		prev = 0;
	}
	else if (*(list->str) == '~')
		(*flag) = 0;
	else
	{
		prev = getcwd(0, BUFFER_SIZE);
		temp = ft_strjoin(prev, "/");
		ft_free(prev);
		prev = temp;
	}
	return (prev);
}

int	ft_cd(t_built *built, t_list *env_list)
{
	t_list	*list;
	char	*prev;
	char	*dest;
	int		flag;
	int		res;

	flag = 1;
	list = built->command->next->next;
	if (built->command->next && built->command->next->next)
		prev = ft_make_str(built, &flag);
	else
		flag = 0;
	if (flag)
		dest = ft_strjoin(prev, list->str);
	else
	{
		prev = ft_getenv(env_list, "HOME", 4);
		dest = ft_strndup(prev, ft_strlen(prev));
	}
	res = chdir(dest);
	ft_free(prev);
	free(dest);
	return (res);
}