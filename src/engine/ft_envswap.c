
#include "head.h"

static int	ft_envlen(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (ft_strchr("$ ><|;", str[i]))
			return (i);
		i++;
	}
	return (i);
}

static char	*ft_strswap(t_list *list, char *old, char *new, int oldlen)
{
	char	*res;

	if (!ft_malloc(&res, sizeof(ft_strlen(list->str) \
									- oldlen + ft_strlen(new))))
		return (0);
	ft_memcpy(res, list->str, old - list->str);
	ft_memcpy(res + (old - list->str), new, ft_strlen(new));
	ft_memcpy(res + (old - list->str) + ft_strlen(new), old + oldlen + 1, \
												ft_strlen(old + oldlen));
	res[ft_strlen(list->str) - oldlen + ft_strlen(new)] = 0;
	ft_free(list->str);
	ft_free(new);
	return (res);
}

int	*ft_envswap(t_list *env, t_list *list)
{
	t_list	*temp_l;
	char	*old;
	char	oldlen;
	char	*new;

	temp_l = list;
	while (temp_l)
	{
	//write(1,"A\n",2);
		old = ft_strchr(temp_l->str, '$');
	//write(1,"B\n",2);

		if (old)
		{
	//write(1,"C\n",2);
			oldlen = ft_envlen(old);
	//write(1,"D\n",2);
			new = ft_getenv(env, old + 1, oldlen);
	//write(1,"E\n",2);
			temp_l->str = ft_strswap(temp_l, old, new, oldlen);
	//write(1,"F\n",2);


		}
		else
			temp_l = temp_l->next;
	}
	//write(1,"E\n",2);


	return (0);
}
