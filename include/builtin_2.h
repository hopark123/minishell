#ifndef BUILTIN_2_H
# define BUILTIN_2_H

# include "head.h"

t_list	*sort_env_list(t_list *env_list);
int	ft_export(t_list *command, t_list *env_list);

#endif
