
#include "head.h"

t_bool	ft_malloc(void *target, int size)
{
	void	**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == NULLPTR)
		return (FALSE);
	return (SUCCESS);
}
