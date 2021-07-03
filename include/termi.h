#ifndef TERMI_H
# define TERMI_H
# include "head.h"

int			ft_putchar_tc(int tc);
void		ft_left_arrow(int *cursor);
void		ft_right_arrow(int *cursor);
void		ft_backspace(int *cursor, int *len);
void		ft_add_history(void);
void		ft_up_arrow(int *cursor, int *len);
void		ft_down_arrow(int *cursor, int *len);
void		ft_init_term(void);
void		ft_reset_term(void);

#endif