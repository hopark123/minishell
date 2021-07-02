#ifndef SUHONG_H
# define SUHONG_H

# define ERROR_BUILT_IN 2
# define ERROR_EXECUTE 126
# define ERROR_COMMAND_NOT_FOUND 127
# define ERROR_INVALID_ARGUMENT 128

# include "head.h"

void	ft_parent(pid_t pid, int *status);
int	ft_status_control(int status);
t_list	*ft_listnew2(char *str, char *id);
t_list	*ft_listdup(t_list *list);

#endif
