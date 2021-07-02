#ifndef HOPARK_H
# define HOPARK_H

# include "head.h"
# include "signal.h"


void	ft_init_get_line(int *cursor, int *len);

void	ft_builtdelone(t_built **built);
int		ft_built_cnt(t_built *built);
int	ft_check_syntax(char *str);

#endif
