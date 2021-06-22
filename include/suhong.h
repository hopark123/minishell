#ifndef SUHONG_H
# define SUHONG_H

# include "head.h"
# include <sys/stat.h>

int	ft_execve(t_built *built, t_list *env_list);
int	check_file_exist(char *name);

#endif
