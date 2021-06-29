/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:13:25 by hjpark            #+#    #+#             */
/*   Updated: 2021/06/29 20:23:25 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_sigint(int code)
{
	write(1, "\b\b", 2);
	printf("[SIGNAL] %d at %s\n", code, __func__);
	exit(0);
}

void	ft_sigquit(int code)
{
	write(1, "\b\b", 2);
	printf("[SIGNAL] %d at %s\n", code, __func__);
	exit(0);
}

void	ft_sigterm(int code)
{
	write(1, "\b\b", 2);
	printf("[SIGNAL] %d at %s\n", code, __func__);
	exit(0);
}

void	ft_signal(void)
{
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, ft_sigquit);
	signal(SIGTERM, ft_sigterm);
}

// void	ft_sigint2(int code)
// {
// 	printf("[SIGNAL]22 %d at %s\n", code, __func__);
// 	exit(0);
// }


// void	ft_signal2(void)
// {
// 	signal(SIGINT, ft_sigint2);
// }
