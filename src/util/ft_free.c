/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:35:06 by hopark            #+#    #+#             */
/*   Updated: 2021/07/05 18:46:03 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_free(void *memory)
{
	if (memory)
	{
		// fprintf(stderr, "@@@[%s]\n", (char *)memory);
			free(memory);
		memory = 0;
	}
}

void	ft_free2(char **s, int i)
{
	while (i--)
	{
		if (s[i])
		{
			// fprintf(stderr, "###[%s]\n", s[i]);
			ft_free(s[i]);
		}
	}
	ft_free(s);
}
