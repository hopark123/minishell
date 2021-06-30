
#include "head.h"

int				ft_num_len(int num)
{
	int		 i = 1;

	while (num /= 10)
		i++;
	return (i);
}