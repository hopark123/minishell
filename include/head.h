#ifndef HEAD_H
# define HEAD_H

# include "type.h"
# include "builtin_2.h"
# include "echo.h"

///////////////engine
t_list	*ft_init_env_list(char **envp);
int		ft_add_env_list(t_list **list, char *id, char *str);
char	*ft_delenv(t_list *list, char *str);
void	ft_show_env_list(t_list *list);
char	*ft_getenv(t_list *list, const char *varname, int varlen);
int		*ft_envswap(t_built *built, t_list *env_list);

///////////////passing
int		ft_parsing(t_built *temp_b, t_list *env_list);
int		ft_split_built(t_built *built);
t_list	*ft_split2(const char *str, const char c);
int	ft_listjoin(t_built *built);

///////////////util
t_built	*ft_builtnup(t_list *list);
void	ft_free(void *memory);
void	ft_free2(char **s, int i);
t_list	*ft_listnew(char *str, char *id);
void	ft_listadd_back(t_list **list, t_list **new);
void	ft_listadd_tail(t_list **list, t_list **new);
void	ft_listdelone(t_list **list);
void	ft_listclear(t_list **list);
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
////////////////////////////////////////
int		get_next_line(int fd, char **line);;


int		ft_del_quotes(t_built *built);
void	ft_del_blank(t_built *built);
void	ft_del_blank2(t_built *built);

#endif
