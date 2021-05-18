
#include "head.h"

void	ft_free(void *memory)
{
	if (memory)
		free(memory);
	memory = 0;
}

void	ft_free2(char **s, int i)
{
	while (i--)
	{
		if (s[i])
			ft_free(s[i]);
	}
	ft_free(s);
}
