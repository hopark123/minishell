#include "head.h"

void	ft_put_blank(t_built *built)
{
	t_list	*temp_l;
	t_list	*new;
	char	*str;

	temp_l = built->command;
	while (temp_l)
	{
		if (!ft_strncmp(temp_l->str, " ", 1) && temp_l->next && !ft_strncmp(temp_l->next->str, " ", 1))
		{
			str = ft_strndup(" ", 1);
			new = ft_listnew(str,0);
			ft_listadd_back(&temp_l, &new);
		}
		temp_l = temp_l->next;
	}
}

t_built	*ft_parse(char *line, t_list *env_list)
{
	t_built	*res;
	t_built	*tmp;

	res = ft_builtndup(ft_split2(line, ' '));
	ft_put_blank(res);
	ft_split_built(res, "|;");
	tmp = res;
	while (tmp)
	{
		test_print_passing(res);
		ft_envswap(tmp, env_list); //>>>>>>>>>>>>>>>>>>> error
		test_print_passing(res);

		ft_del_quotes(tmp);
		test_print_passing(res);

		ft_del_blank(tmp);
		test_print_passing(res);

		ft_del_blank2(tmp);
		test_print_passing(res);

		ft_listjoin(tmp);
		test_print_passing(res);

		ft_del_lastblank(tmp);
		test_print_passing(res);

		tmp = tmp->next;
	}
	ft_free(g_mini.line);
	return (res);
}
