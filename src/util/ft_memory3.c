#include "head.h"

static int	p(char c)
{
	return (c >= 32 && c < 127);
}

int	ft_isprint(int n)
{
	// char a;
	// char b;
	// char c;
	// char d;

	// a = (char)n;
	// b = (char)(n >> 8);
	// c = (char)(n >> 16);
	// d = (char)(n >> 24);
	return (n >= 32 && n < 127);
	// return (	return (c >= 32 && c < 127);
}