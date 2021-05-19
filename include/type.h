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
# define ERROR  0
# define SUCCESS 1
# define FAIL -1
# define NULLPTR 0


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

typedef int			t_bool;

#endif
