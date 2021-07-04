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

	if (!(**spot) || len == 0)
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
	// fprintf(stderr, "@@@@new[%s]\n", str);
	add = ft_listnew2(ft_substr(*spot, 0, len), str_id);
	ft_listadd_tail(&token, &add);
	return (token);
}

static int	ft_make_token(t_list **token, char **spot, char **str, int *q_tmp)
{
	int		i;

	i = 1;
	if ((**spot) && (**str == 0 || **str == ' '))
	{
		(*token) = build_token((*token), spot, (*str) - (*spot), *q_tmp);
		*q_tmp = 0;
		(*spot) = 0;
	}
	else if (ft_strchr("><;|", **str))
	{
		(*token) = build_token((*token), spot, (*str) - (*spot), *q_tmp);
		*q_tmp = 0;
		if (ft_strchr("><", **str) && **str == *(*str + 1))
			i++;
		(*token) = build_token((*token), str, i, **str);
		(*spot) = 0;
	}
	return (i);
}

static void	split_init(t_list **token, char **spot, int *q_tmp, int *q_flag)
{
	(*token) = 0;
	(*spot) = 0;
	(*q_tmp) = 0;
	(*q_flag) = 0;

}

t_list	*ft_token_split(char *str)
{
	t_list	*token;
	char	*spot;
	int		q_flag;
	int		q_tmp;
	int		i;

	split_init(&token, &spot, &q_tmp, &q_flag);
	while (*str >= 0)
	{
		i = 1;
		if (!spot)
		{
			while (*str == ' ')
				str++;
			spot = str;
		}
		q_flag = check_quotes(*str, &q_tmp);
		if (!q_flag)
			i = ft_make_token(&token, &spot, &str, &q_tmp);
		if (*str == 0)
			break ;
		str = str + i;
	}
	check_quotes(0, 0);
	return (token);
}
