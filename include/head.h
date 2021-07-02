#ifndef HEAD_H
# define HEAD_H

# include "type.h"
# include "builtin.h"
# include "hopark.h"
# include "suhong.h"

//////////////sigint
void	ft_sigint(int code);
void	ft_sigquit(int code);
void	ft_sigterm(int code);
void	ft_signal(void);
void	ft_sigint2(int code);
void	ft_signal2(void);
///////////////term
int		ft_putchar_tc(int tc);
void	ft_left_arrow(int *cursor, int *len);
void	ft_right_arrow(int *cursor, int *len);
void	ft_backspace(int *cursor, int *len);
void	ft_add_history(void);
void	ft_up_arrow(int *cursor, int *len);
void	ft_down_arrow(int *cursor, int *len);

void	ft_get_line(void);
char	*ft_add_char(char *str, char c, int pt);
char	*ft_del_char(char *str, int pt);

///////////////debug
void	test_print_passing(t_built *built);
void	print_built_list(t_built *built);
///////////////error
void	ft_perror(char *filename, char *message);
void	ft_error(char *str);
///////////////pipe
int	**free_pipe(int ***pipe, int size);
int	count_pipe(t_built *built);
int	**init_pipe(int size);
int	get_pipe_size(int **pipe);
///////////////shell
int	ft_execve(t_built *built, t_list *env_list);
int	ft_subshell(t_built *built, t_list **env_list, int **fd, int order);
void	ft_shell(t_built *built, t_list **env_list);
///////////////engine
t_list	*ft_init_env_list(char **envp);
int		ft_add_env_list(t_list **list, char *id, char *str);
void	ft_delenv(t_list **list, char *str);
void	ft_show_env_list(t_list *list, char *str);
char	*ft_getenv(t_list *list, const char *varname, int varlen);
int		*ft_envswap(t_built *built, t_list *env_list);
int		ft_execute(t_built *built, t_list **env_list);
int		ft_execute2(t_built *built, t_list **env_list, int *fd);
int		ft_builtin(t_built *temp_b, t_list **env_list);
int		ft_exit(t_built *built);
////////////init
void	ft_init_term(void);
void	ft_reset_term(void);
void	ft_init_termcap(void);

//////////redirect
int		ft_redirect(t_built *built, char *type, int *fd);
int		ft_redirect2(t_built *built, int *fd);
int		ft_redirect3(t_built *built, int *fd);
///////////////passing
int		ft_split_built(t_built *built, char *str);
t_list	*ft_split2(char *str, char c);
int		ft_listjoin(t_built *built);
t_built	*ft_parse(char *line, t_list *env_list);
void	ft_del_lastblank(t_built *built);

///////////////util
t_built	*ft_builtndup(t_list *list);
void	ft_free(void *memory);
void	ft_free2(char **s, int i);
t_list	*ft_listnew(char *str, char *id);
void	ft_listadd_back(t_list **list, t_list **new);
void	ft_listadd_front(t_list **list, t_list **new);
void	ft_listadd_tail(t_list **list, t_list **new);
void	ft_listdelone(t_list **list);
void	ft_listclear(t_list **list);
char	**ft_listtochar(t_list *list);
t_bool	ft_malloc(void *target, int size);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strndup(const char *s, int len);
char	*ft_strchr(const char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strncmp2(const char *s1, const char *s2, int n);
int		ft_strncmp3(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_putchar_fd(char c, int fd, char *color);
int		ft_putstr_fd(char *s, int fd, char *color);
int		ft_putnbr_fd(int n, int fd, char *color);
int		ft_strlen2(char **s);
char	*ft_itoa(int n);
int		ft_close(int fd);
int		ft_guard_next(t_built *built, int n);
int		ft_atoi(const char *nptr);
int		ft_num_len(int num);
int		ft_is_num(const char *nptr);
int		ft_isprint(int c);

////////////////////////////////////////
int		get_next_line(int fd, char **line);;


int		ft_del_quotes(t_built *built);
void	ft_del_blank(t_built *built);
void	ft_del_blank2(t_built *built);
void	ft_del_blank3(t_built *built);

int	check_file_exist(char *name);

void	draw(void);
void	draw2(void);
#endif
