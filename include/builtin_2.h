#ifndef BUILTIN_2_H
# define BUILTIN_2_H

# include "head.h"

int	ft_export(t_built *built, t_list *env_list);
int	ft_unset(t_built *built, t_list *env_list);
int	ft_env(t_built *built, t_list *env_list);

#endif
