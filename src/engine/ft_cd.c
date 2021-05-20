/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:06:01 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 14:04:16 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_cd(t_built *built, t_list *env_list)
{
	t_list	*list;
	char	*cwd;
	char	*temp;
	int		res;
	int		i;

	list = built->command;
	if (list->next && list->next->next && (*list->next->next->str) != '~')
	{

		list = list->next->next;
		cwd = getcwd(0, BUFFER_SIZE);
		if ('/' != *(list->str))
		{
			temp = ft_strjoin(cwd, "/");
			free(cwd);
			cwd = temp;
		}
		while ((list) && (*list->str) == '.')
		{
			write(1,"[\n",2);
			temp = ft_strjoin(cwd, ".");
			free(cwd);
			cwd = temp;
			list = list->next;
			write(1,"]\n",2);
		}
			write(1,"A\n",2);

		temp = ft_strjoin(cwd, list->str);
			write(1,"B\n",2);

		free(cwd);
		cwd = temp;
			write(1,"C\n",2);

												//printf("\n**|%s|**\n",cwd);
	}
	else 
	{
		cwd = ft_getenv(env_list, "HOME", 4);
												//printf("\n@@|%s|@@\n",cwd);
	}
	res = chdir(cwd);
	free(cwd);
								//write(1, ">>>>cwd{",9);
								//cwd = getcwd(0, BUFFER_SIZE);
								//ft_putstr_fd(cwd, 1, 0);
								//write(1, "}\n",2);
								//// errno 처리 필요
	return (res);
}
