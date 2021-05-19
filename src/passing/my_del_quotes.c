#include "head.h"

int	my_ft_del_quotes(t_built *built)
{
	t_list	*tmp;
	char	*new;
	char	*head;
	char	*tail;

	tmp = built->command;
	while (tmp)
	{
		head = &tmp->str[0];
		tail = &tmp->str[ft_strlen(tmp->str) - 1];
		if ((head <= tail) && (*head == '"' || *head == '\''))
			head++;
		if ((head <= tail) && (*tail == '"' || *tail == '\''))
			tail--;
		new = ft_substr(head, 0, tail - head + 1);
		if (!new)
			return (ERROR);
		ft_free(tmp->str);
		tmp->str = new;
		tmp = tmp->next;
	}
	return (SUCCESS);
}
