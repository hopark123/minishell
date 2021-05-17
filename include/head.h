#ifndef HEAD_H
# define HEAD_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <locale.h>
# include <limits.h>
# include <termios.h>
# include <errno.h>

# define ERROR  0
# define SUCCESS 1
# define FAIL -1
# define NULLPTR 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX  10240
# endif

typedef struct s_list
{
	char			*str;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_built
{
	struct s_list	*command;
	struct s_built	*prev;
	struct s_built	*next;
}				t_built;

typedef int			t_bool;
void	ft_putchar_fd(char c, int fd, char *color);
void	ft_putstr_fd(char *s, int fd, char *color);
void	ft_putnbr_fd(int n, int fd, char *color);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strndup(const char *s, int len);
char	*ft_strchr(const char *s, char c);
int		get_next_line(int fd, char **line);;
t_bool	ft_malloc(void *target, int size);
void	ft_free(void *memory);
void	ft_free2(char **s, int i);

t_list	*ft_listnew(char *str);
void	ft_listadd_front(t_list **list, t_list **new);
void	ft_listadd_tail(t_list **list, t_list **new);
void	ft_listdelone(t_list **list);
void	ft_listclear(t_list **list);

t_list	*ft_split(const char *str, const char c);
void	ft_split_built(t_built *built);

#endif