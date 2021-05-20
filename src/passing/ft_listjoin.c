/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:38:13 by hopark            #+#    #+#             */
/*   Updated: 2021/05/20 20:03:40 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_listjoin(t_built *built)
{
	t_list	*temp_l;
	t_list	*temp_l2;
	char	*temp_s;

	temp_l = built->command;
	while (temp_l)
	{
		//write(1,"A\n",2);
		if (temp_l->str && *(temp_l->str) != ' ' && temp_l->next && *(temp_l->next->str) != ' ')
		{
			//write(1,"B\n",2);

			temp_s = ft_strjoin(temp_l->str, temp_l->next->str);
			ft_free(temp_l->str);
			temp_l->str = temp_s;
			ft_putstr_fd(temp_l->str,1 , 0);
			write(1,"\n",1);
			ft_listdelone(&(temp_l->next));
			write(1,"C\n",2);
		}
		temp_l = temp_l->next;
		write(1,"D\n",2);
		printf("@@%s@@\n", temp_l->str);
	}
		write(1,"E\n",2);

}
