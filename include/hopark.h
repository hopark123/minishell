#ifndef HOPARK_H
# define HOPARK_H

# include "head.h"
void	test_print_passing(t_built *built);
int	ft_execute2(t_built *built, t_list *env_list, int *fd);
int	ft_redirect(t_built *built, char *type, int *fd);
int	ft_redirect2(t_built *built, char *type, int *fd);

void	ft_close(int fd);

#endif