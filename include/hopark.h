#ifndef HOPARK_H
# define HOPARK_H

# include "head.h"
# include "signal.h"

void	test_print_passing(t_built *built);
int	ft_execute2(t_built *built, t_list *env_list, int *fd);
int	ft_redirect(t_built *built, char *type, int *fd);
int	ft_redirect2(t_built *built, int *fd);
int	ft_redirect3(t_built *built, int *fd);
void	ft_del_lastblank(t_built *built);
int	ft_close(int fd);
void	ft_builtclear(t_built **built);
int	ft_guard_next(t_built *built, int n);
void	ft_del_blank3(t_built *built);
int	ft_exit(t_built *built);
int	ft_is_num(const char *nptr);
int	ft_atoi(const char *nptr);
void	print_built_list(t_built *built);

int	ft_strlen2(char **s);

void	ft_sigint(int code);
void	ft_sigquit(int code);
void	ft_sigterm(int code);
void	ft_signal(void);

typedef struct s_mini
{
	int			pip[2];
	int			signal;
}				t_mini;

t_mini		g_mini;

#endif