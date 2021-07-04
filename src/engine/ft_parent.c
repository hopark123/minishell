/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 22:58:51 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/04 22:58:54 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	ft_status_control(int status)
{
	int	signal;

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		return (128 + signal);
	}
	return (ERROR);
}

void	ft_parent(pid_t pid, int *status)
{
	waitpid(pid, status, WUNTRACED);
	while (!WIFEXITED(*status) && !WIFSIGNALED(*status))
		waitpid(pid, status, WUNTRACED);
}
