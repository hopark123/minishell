#include "head.h"

static int	check_quotes(char c, int *q_tmp)
{
	static char	tmp = 0;

	if (!c || c == tmp)
	{
		tmp = 0;
	}
	else if (ft_strchr("\"\'", c) && !tmp)
	{
		tmp = c;
	}
	if (tmp && q_tmp)
		*q_tmp = tmp;
	return (tmp);
}

static t_list	*build_token(t_list *token, char **spot, int len, int id)
{
	t_list	*add;
	t_list	*space;
	char	*str_id;
	char	*str;

	if (!(**spot))
		return (token);
	str_id = 0;
	if (id)
	{
		if (!ft_malloc(&str_id, sizeof(char) * 2))
			ft_error("malloc error");
		str_id[0] = (char)id;
		str_id[1] = 0;
	}
	str = ft_substr(*spot, 0, len);
	add = ft_listnew2(ft_substr(*spot, 0, len), str_id);
	ft_listadd_tail(&token, &add);
	return (token);
}

// static void	split_order(t_list **token, char *start, char *end)
// {
// 	char	*tmp;
// 	char	*spot;

// 	tmp = start;
// 	while (tmp < end)
// 	{
// 		spot = ft_strnstr(tmp, )
// 		tmp++;
// 	}
// }

t_list	*ft_token_split(char *str, char c)
{
	t_list	*token;
	char	*spot;
	int		q_flag;
	int		q_tmp;

	spot = 0;
	token = 0;
	q_tmp = 0;
	while (*str >= 0)
	{
		q_flag = check_quotes(*str, &q_tmp);
		if (!spot && *str != c)
			spot = str;
		else if (!q_flag && spot && (*str == c || *str == 0))
		{
			token = build_token(token, &spot, str - spot, q_tmp);
			token = build_token(token, &str, 1, c);
			spot = 0;
		}
		if (*str == 0)
			break ;
		str++;
	}
	return (token);
}
