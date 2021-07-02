#ifndef HOPARK_H
# define HOPARK_H

# include "head.h"
# include "signal.h"


void	ft_init_get_line(int *cursor, int *len);
void	ft_syntaxerror(char type);



void	ft_builtdelone(t_built **built);
int		ft_built_cnt(t_built *built);
int	ft_check_syntax(char *str);
void	proc_signal_handler(int signo);
void	signal_handler(int signo);
char	**ft_env_listtochar(t_list *list);


#endif
