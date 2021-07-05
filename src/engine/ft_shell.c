/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 06:02:19 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/05 22:56:56 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	run_subshell(t_built **built, t_list **env_list)
{
	int	order;
	int	**fd;
	int	size;

	order = 0;
	size = count_pipe(*built);
	fd = init_pipe(size);
	if (!fd)
		ft_error("malloc error");
	while (*built && order <= size)
	{
		g_mini.status = ft_subshell(*built, env_list, fd, order);
		*built = (*built)->next;
		order++;
	}
	free_pipe(&fd, size);
}

// void	ft_shell(t_built *built, t_list **env_list)
// {
// 	g_mini.status = SUCCESS;
// 	while (built && g_mini.status == SUCCESS)
// 	{
// 		if (built->next && built->next->command->str && built->next->command->str[0] == '|')
// 		{
// 			run_subshell(&built, env_list);
// 		}
// 		else if (built->command->str[0] == ';' && !built->command->next)
// 		{
// 			break ;
// 		}
// 		else
// 		{
// 			g_mini.status = ft_execute(built, env_list);
// 			built = built->next;
// 		}
// 	}
// }

void	ft_shell(t_built *built, t_list **env_list)
{
	g_mini.status = SUCCESS;
	while (built && g_mini.status == SUCCESS)
	{
		if (built->next)
		// if (built->next && built->next->command->str && built->next->command->str[0] == '|')
		{
			write(2,"@\n",2);
			if (built->next->command)
			{
				if (built->next->command->str)
				{
					if (built->next->command->str[0] == '|')
						run_subshell(&built, env_list);
				}
			}
		}
		else if (built->command->str)
		// else if (built->command->str[0] == ';' && !built->command->next)
		{
			if (built->command->str[0] == ';')
			{
				break ;
			}
		}
		else
		{
			g_mini.status = ft_execute(built, env_list);
			built = built->next;
		}
	}
}
