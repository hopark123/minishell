#include "head.h"

static int	p(char c)
{
	return (c >= 32 && c < 127);
}

int	ft_isprint(int n)
{
	char c;

	c = (char)n;
	return (c >= 32 && c < 127);
}
