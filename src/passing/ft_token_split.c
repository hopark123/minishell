#include <head.h>

static int	check_quotes(char c)
{
	static char	tmp = 0;

	if (!c || c == tmp)
	{
		tmp = 0;
		return (tmp);
	}
	if (ft_strchr("\"\'", c) && !tmp)
	{
		tmp = c;
		return (tmp);
	}
	return (tmp);
}

static size_t	count_token(char const *str, char c)
{
	size_t	size;
	size_t	i;
	int		p_flag;
	int		q_flag;

	size = 0;
	i = 0;
	p_flag = 0;
	while (str[i])
	{
		q_flag = check_quotes(str[i]);
		if (str[i] != c && !p_flag)
		{
			p_flag = 1;
		}
		else if (str[i] == c && !q_flag && p_flag)
		{
			p_flag = 0;
			size++;
		}
		i++;
	}
	check_quotes(0);
	return (size + p_flag);
}

static t_list	*build_token(t_list *token, char **spot, char **str, int quotes)
{
	t_list	*add;
	t_list	*space;
	char	*str_quotes;

	str_quotes = 0;
	if (quotes)
	{
		if (!ft_malloc(&str_quotes, sizeof(char) * 2))
			ft_error("malloc error");
		str_quotes[0] = (char)quotes;
		str_quotes[1] = 0;
	}
	add = ft_listnew2(ft_substr(*spot, 0, *str - *spot), str_quotes);
	// fprintf(stderr, "[%s]str_id[%s]\n", add->str, add->id);
	ft_listadd_tail(&token, &add);
	return (token);
}

t_list	*ft_token_split(char *str, char c)
{
	t_list	*token;
	size_t	size;
	char	*spot;
	int		q_flag;
	int		q_tmp;

	spot = 0;
	token = 0;
	q_tmp = 0;
	size = count_token(str, c);
	while (size && *str >= 0)
	{
		q_flag = check_quotes(*str);
		if (q_flag)
			q_tmp = q_flag;
		if (*str != c && !spot)
			spot = str;
		else if (!q_flag && spot && (*str == c || !*str))
		{
			token = build_token(token, &spot, &str, q_tmp);
			size--;
			spot = 0;
		}
		str++;
	}
	return (token);
}
