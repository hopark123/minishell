/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:20:30 by suhong            #+#    #+#             */
/*   Updated: 2021/06/21 22:28:57 by hjpark           ###   ########.fr       */
=======
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:20:30 by suhong            #+#    #+#             */
/*   Updated: 2021/06/21 22:09:06 by suhong           ###   ########.fr       */
>>>>>>> c146828ab40fc9ccbf00793779472e0308c1de4d
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_unset(t_built *built, t_list *env_list)
{
	t_list	*i;

	if (!ft_strncmp2(built->command->next->str, " ", 1))
		return (ERROR);
	i = built->command->next->next;
	while (i)
	{
		if (!ft_strncmp2(i->str, " ", 1))
			ft_delenv(env_list, i->str);
		i = i->next;
	}
	return (1);
}
