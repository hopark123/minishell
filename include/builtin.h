#ifndef BUILTIN_H
# define BUILTIN_H

# include "head.h"

int	ft_export(t_built *built, t_list **env_list);
int	ft_unset(t_built *built, t_list **env_list);
int	ft_env(t_built *built, t_list *env_list);
int	ft_echo(t_built *built);
int	ft_cd(t_built *built, t_list *env_list);
int	ft_pwd(void);

#endif
