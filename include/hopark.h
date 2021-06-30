#ifndef HOPARK_H
# define HOPARK_H

# include "head.h"
# include "signal.h"
# include <termios.h>
# include <termcap.h>
# include <readline/readline.h>
# include <readline/history.h>


# define BACKSPACE 127
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699


t_built	*ft_parse(char *line, t_list *env_list);
void	draw(void);
void	draw2(void);

void	test_print_passing(t_built *built);
int		ft_execute2(t_built *built, t_list *env_list, int *fd);
int		ft_redirect(t_built *built, char *type, int *fd);
int		ft_redirect2(t_built *built, int *fd);
int		ft_redirect3(t_built *built, int *fd);
void	ft_del_lastblank(t_built *built);
int		ft_close(int fd);
void	ft_builtclear(t_built **built);
int		ft_guard_next(t_built *built, int n);
void	ft_del_blank3(t_built *built);
int		ft_exit(t_built *built);
int		ft_is_num(const char *nptr);
int		ft_isprint(int c);

int		ft_atoi(const char *nptr);
void	print_built_list(t_built *built);

int		ft_strlen2(char **s);
char	*ft_add_char(char *str, char c, int pt);
char	*ft_del_char(char *str, int pt);


void	ft_sigint(int code);
void	ft_sigquit(int code);
void	ft_sigterm(int code);
void	ft_signal(void);

void	ft_sigint2(int code);
void	ft_signal2(void);


void	ft_listadd_front(t_list **list, t_list **new);
int		ft_num_len(int num);

int		ft_putchar_tc(int tc);
void	ft_getchar(int *cursor, int *len, int n);
void	ft_get_line(void);
void	ft_left_arrow(int *cursor, int *len);
void	ft_right_arrow(int *cursor, int *len);
void	ft_backspace(int *cursor, int *len);

void	ft_add_history(void);
void	ft_up_arrow(int *cursor, int *len);
void	ft_down_arrow(int *cursor, int *len);

void	ft_init_term(void);
void	ft_reset_term(void);
void	ft_init_termcap(void);




typedef struct s_mini
{
	int			pip[2];
	int			signal;
	char		*line;
	struct termios	term;
	struct termios	backup;

	int			len;
	int			cursor;
	t_list		*history;
	t_list		*head;
	char		*cm;
	char		*ce;
}				t_mini;

t_mini		g_mini;

#endif