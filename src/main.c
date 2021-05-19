/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:34:44 by hopark            #+#    #+#             */
/*   Updated: 2021/05/19 15:47:43 by hopark           ###   ########.fr       */
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


int	main(int ac, char **av, char **envp)
{
	char	*s;
	char	*line;
	t_built	*built;
	t_list	*env_list;

	if (!(ft_malloc(&built, sizeof(built))))
		return (ERROR);
	built->command = 0;
	built->prev = 0;
	built->next = 0;

	if (!ft_malloc(&s, sizeof(char) * 1024))
		return (ERROR);
	draw(0);
	getcwd(s, BUFFER_SIZE);
	ft_putstr_fd(s, 1, 0);
	free(s);
	write(1,"$ ", 2);
	get_next_line(0, &line);
	built->command = ft_split2(line, ' ');
	free(line);
	ft_split_built(built);
	env_list = ft_init_env_list(envp);

																t_list	*lista = env_list;
																///환경변수 출력
																//write(1,"**********************\n",24);
																//while (lista)
																//{
																//		ft_putstr_fd(lista->id, 1, 0);
																//	write(1,"=",1);
																//		ft_putstr_fd(lista->str, 1, 0);
																//	write(1,"\n",1);
																//	if(lista->next)
																//		lista = lista->next;
																//	else
																//		break;
																//}
																//write(1,"**********************\n",24);
	t_built *temp_b = built;
																t_list *temp_l = built->command;
																int		i = 0;
																while (temp_b)
																{
																	temp_l = temp_b->command;
																	ft_putnbr_fd(i++, 1, 0);
																	write(1,"/",1);

																	while (temp_l)
																	{
																	write(1,"[",1);
																	ft_putstr_fd(temp_l->str, 1, 0);
																	write(1,"]",1);
																	if (temp_l->next)
																		temp_l = temp_l->next;
																	else
																		break ;
																	}
																	write(1,"\n",1);
																	if (temp_b->next)
																		temp_b = temp_b->next;
																	else
																		break;
																	//write(1,"}\n",2);
																}
																write(1,"\n",1);
																temp_b = built;
																i = 0;
	while (temp_b)
	{
		ft_envswap(temp_b, env_list);
		ft_del_quotes(temp_b);
																ft_putnbr_fd(i++, 1, 0);
																temp_l = temp_b->command;
																while (temp_l)
																{
																write(1,"[",1);
																ft_putstr_fd(temp_l->str, 1, 0);
																write(1,"]",1);
																if (temp_l->next)
																	temp_l = temp_l->next;
																else
																	break ;
																}
																write(1,"\n",1);
		ft_parsing(temp_b, env_list);
		if (temp_b->next)
			temp_b = temp_b->next;
		else
			break;
	}
}
