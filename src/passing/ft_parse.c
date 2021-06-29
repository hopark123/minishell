#include "head.h"


t_built	*ft_parse(char *line, t_list *env_list)
{
	t_built	*res;
	t_built	*tmp;

	res = ft_builtndup(ft_split2(line, ' '));
	ft_split_built(res, "|;");
	tmp = res;
	while (tmp)
	{
		ft_envswap(tmp, env_list);
		ft_del_quotes(tmp);
		ft_del_blank(tmp);
		ft_del_blank2(tmp);
		ft_listjoin(tmp);
		ft_del_lastblank(tmp);
		tmp = tmp->next;
	}
	free(g_mini.line);
	return (res);
}
