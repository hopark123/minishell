/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:26:20 by hopark            #+#    #+#             */
/*   Updated: 2021/05/17 19:46:22 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:58:35 by hopark            #+#    #+#             */
/*   Updated: 2021/05/10 20:33:12 by hopark           ###   ########.fr       */
=======
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:17:58 by suhong            #+#    #+#             */
/*   Updated: 2021/05/17 20:41:44 by suhong           ###   ########.fr       */
>>>>>>> 03f0d6cde2b84ca2cb37292e5b353ca5bd207876
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

<<<<<<< HEAD
int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (0);
		i++;
	}
	return (1);
=======
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*b;

	i = 0;
	f = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (i < n && f[i] != '\0' && b[i] != '\0')
	{
		if (f[i] > b[i])
			return (1);
		if (b[i] > f[i])
			return (-1);
		i++;
	}
	if (i < n)
	{
		if (f[i] != '\0')
			return (1);
		if (b[i] != '\0')
			return (-1);
	}
	return (0);
>>>>>>> 03f0d6cde2b84ca2cb37292e5b353ca5bd207876
}
