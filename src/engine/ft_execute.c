/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:07 by suhong            #+#    #+#             */
/*   Updated: 2021/06/21 20:23:36 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_execute(t_built *built, t_list *env_list)
{
	t_built	*temp;
	int		fd[2];

	fd[0] = -1;
	fd[1] = -1;
	temp = ft_builtndup(built->command);
	ft_split_built(temp, "><");
	ft_execute2(temp, env_list, &fd);
	printf("@@%d\n", fd[0]);
	dup2(STDOUT, fd[1]);
	ft_close(fd[0]);
	ft_close(fd[1]);
	return (1);
}

int	ft_execute2(t_built *built, t_list *env_list, int *fd)
{
	if (!built)
		return (0);
	test_print_passing(built);
	printf("{%s}\n", built->command->str);
	printf("##%d\n", fd[0]);

	if (built->next)
		ft_execute2(built->next, env_list, fd);
	if (ft_strncmp(built->command->str, ">", 1))
	{
		ft_redirect(built, "TRUNC", fd);
	printf("UU%d\n", fd[0]);

	}
	else if (ft_strncmp(built->command->str, ">>", 2))
		ft_redirect(built, "APPEND", fd);
	// else if (ft_strncmp(built->command->str, "<", 1))
	// 	ft_redirect(built, 1);
	// else if (ft_strncmp(built->command->str, "<<", 2))
	// 	ft_redirect(built, 1);
	else
		ft_builtin(built, env_list);

}

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

int	ft_redirect(t_built *built, char *type, int *fd)
{
	t_list	*list;

	ft_close(fd[0]);
	list = built->command;
	if (!list->next || !list->next->next)
		return (ERROR);
	list = list->next->next;
	if (ft_strncmp(type, "TRUNC", 5))
	{
		fd[0] = open(list->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	}
	else if (ft_strncmp(type, "APPEND", 6))
		fd[0] = open(list->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	printf("**%d\n", fd[0]);
	dup2(fd[0], STDOUT);
	printf("**%d\n", fd[0]);
}
