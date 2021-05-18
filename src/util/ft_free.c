/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:06 by hopark            #+#    #+#             */
/*   Updated: 2021/05/18 15:35:08 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_free(void *memory)
{
	if (memory)
		free(memory);
	memory = 0;
}

void	ft_free2(char **s, int i)
{
	while (i--)
	{
		if (s[i])
			ft_free(s[i]);
	}
	ft_free(s);
}
