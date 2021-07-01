#ifndef TYPE_H
# define TYPE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <locale.h>
# include <limits.h>
# include <termios.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <termios.h>
# include <termcap.h>
# include <readline/readline.h>
# include <readline/history.h>
# define ERROR  1
# define SUCCESS 0
# define FAIL -1
# define NULLPTR 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define REDIRECTION_ERROR 258

# define BACKSPACE 127
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX  10240
# endif

typedef struct s_list
{
	char			*str;
	char			*id;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_built
{
	struct s_list	*command;
	struct s_built	*prev;
	struct s_built	*next;
}				t_built;
typedef struct s_mini
{
	int			pip[2];
	int			signal;
	int			status;
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

typedef int			t_bool;

#endif
