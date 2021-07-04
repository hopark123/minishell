#include "head.h"

int	*ft_del_quotes(t_list *list)
{
	int			i;
	char		c;
	int			temp;

	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			// fprintf(stderr, "[%s][%s]\n", list->str, &list->str[i]);
			if (ft_strchr("\'\"", list->str[i]))
			{
				// fprintf(stderr, "1[%s][%s]\n", list->str, &list->str[i]);
				c = list->str[i];
				list->str = ft_del_char(list->str, i + 1);
				// fprintf(stderr, "2[%s][%s]\n", list->str, &list->str[i]);
				temp = ft_strchr(&list->str[i], c) - list->str;
				// fprintf(stderr, "temp : [%s] [%ld]\n", temp, temp - list->str + 1);
				list->str = ft_del_char(list->str, temp + 1);
				// fprintf(stderr, "3[%s][%s]\n", list->str, &list->str[i]);
				i = temp;
			}
			else
				i++;
		}
		list = list->next;
	}
}
