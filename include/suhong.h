#ifndef SUHONG_H
# define SUHONG_H

# include "head.h"
# include <sys/stat.h>

int	ft_execve(t_built *built, t_list *env_list);
int	check_file_exist(char *name);
void	ft_del_blank3(t_built *built);
int	ft_subshell(t_built *built, t_list *env_list, int *fd);
int ft_start(t_built *built, t_list *env_list);

#endif
