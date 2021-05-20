/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:23:24 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 12:49:07 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_pwd(t_built *built)
{
	char	*cwd;

	cwd = getcwd(0, BUFFER_SIZE);
	ft_putstr_fd(cwd, 1, 0);
	ft_putchar_fd('\n', 1, 0);
	ft_free(cwd);
	return (SUCCESS);
}
