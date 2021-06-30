#include "head.h"

char	*ft_add_char(char *str, char c, int pt)
{
	int		len;
	char	*result;

	pt--;
	len = ft_strlen(str);
	if (!(ft_malloc(&result, sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(result, str, pt);
	result[pt] = c;
	ft_memcpy(result + pt + 1, str + pt, len - pt);
	result[len + 1] = 0;
	ft_free(str);
	return (result);
}

char	*ft_del_char(char *str, int pt)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	if (!(ft_malloc(&result, sizeof(char) * (len - 1))))
		return (0);
	ft_memcpy(result, str, pt - 1);
	ft_memcpy(result + pt - 1, str + pt, len - pt);
	result[len - 1] = 0;
	ft_free(str);
	return (result);
}
