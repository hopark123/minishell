/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:03:34 by hopark            #+#    #+#             */
/*   Updated: 2021/05/16 16:03:47 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	draw(char	*s)
{
	s = 0;
	ft_putstr_fd("                          f)}\"\\__Xoo2o2o2o2on_sr\"{;]                           \n", 1, "\033[33m");
	ft_putstr_fd("                            _<S2XX2oo2o2o2o2o2Snoos,                            \n", 1, "\033[33m");
	ft_putstr_fd("                          _xooooooo2o2o2o2o2o2ooooons,                        \n", 1, "\033[33m");
	ft_putstr_fd("                        'Jno2r\"\"\"\"\"\"2o2o2o2o\"\"\"\"\"\"{2oos\"                        \n", 1, "\033[33m");
	ft_putstr_fd("                        ooo2o222S22So2o2o2o22222S2So2ooo                       \n", 1, "\033[33m");
	ft_putstr_fd("                        o2o2oo2o( )oo2o2oo2oo( )noooo2oo                        \n", 1, "\033[33m");
	ft_putstr_fd("                        2o2o2o2o222or\"\"\"\"\"\"{So2ooo2o2o2o                        \n", 1, "\033[33m");
	ft_putstr_fd("                        {oo2o2o2oor_j  aa  b/1o2o2o2o2or]                       \n", 1, "\033[33m");
	ft_putstr_fd("                         {o2o2o2o2o,????????_2o2oo2o2or_                        \n", 1, "\033[33m");
	ft_putstr_fd("                          \"oo2oo2o2S222oo2o222o2o2o2o^a                         \n", 1, "\033[33m");
	ft_putstr_fd("                            \"{2o2o2oooo22o2oo2o2o2r\"a                           \n", 1, "\033[33m");
	ft_putstr_fd("                             \'_%\"{oo2o2oo2o2o2}\"\\_)                             \n", 1, "\033[33m");
	ft_putstr_fd("                            _oX22os__s_%__s__anoo2o,4                           \n", 1, "\033[33m");
	ft_putstr_fd("                           .Sor{ooomm22 mX2 mooor{o2,4                          \n", 1, "\033[33m");
	ft_putstr_fd("                           )no()n          W  po()no(]                          \n", 1, "\033[33m");
	ft_putstr_fd("                          [{oo()vm        W   mo()non.                          \n", 1, "\033[33m");
	ft_putstr_fd("                           )no()v$            Do(=no(]                          \n", 1, "\033[33m");
	ft_putstr_fd("                           ,{o()voW          @no(=2}_                           \n", 1, "\033[33m");
	ft_putstr_fd("                            aa/)noodVU$  @VUnnoo(_aa                            \n", 1, "\033[33m");
	ft_putstr_fd("                              [)vo2oo_ aa _2oo2o(]                              \n", 1, "\033[33m");
	ft_putstr_fd("                              f)no2ooe.  ,{Xo2o2(]", 1, "\033[33m");
	ft_putstr_fd("        @hopark @suhong        \n", 1, "\033[36m");
	ft_putstr_fd("                              g {Soo2'j  b-2oo2e'j                              \n", 1, "\033[33m");
	ft_putstr_fd("                                aaggaj    baggaa              \n", 1, "\033[33m");

}

int	main(int ac, char **av)
{
	char	*s;
	char	*line;
	t_built	*built;

	if (!(ft_malloc(&built, sizeof(built))))
		return (ERROR);
	built->command = 0;
	built->prev = 0;
	built->next = 0;

	ac = 0;
	av = 0;
	draw(0);
	if (!ft_malloc(&s, sizeof(char) * 1024))
		return (ERROR);
	getcwd(s, 1024);
	ft_putstr_fd(s, 1, 0);
	write(1," ", 1);
	get_next_line(0, &line);
	built->command = ft_split(line, ' ');
	t_list *list = built->command;
	while (list)
	{
		write(1,"@",1);
		ft_putstr_fd(list->str, 1, 0);
		write(1,"@",1);
		write(1,"\n",1);
		list = list->next;
	}
	// ft_split_built(built);
}

