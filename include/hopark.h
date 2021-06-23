#ifndef HOPARK_H
# define HOPARK_H

# include "head.h"
void	test_print_passing(t_built *built);
int	ft_execute2(t_built *built, t_list *env_list, int *fd);
int	ft_redirect(t_built *built, char *type, int *fd);
int	ft_redirect2(t_built *built, char *type, int *fd);
void	ft_del_lastblank(t_built *built);
void	ft_close(int fd);
void	ft_builtclear(t_built **built);
int	ft_guard_next(t_built *built, int n);
void	ft_del_blank3(t_built *built);

int	ft_exit(t_built *built);
int	ft_is_num(const char *nptr);
int	ft_atoi(const char *nptr);

#endif