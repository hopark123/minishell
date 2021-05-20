#ifndef ECHO_H
# define ECHO_H
# define READ 0
# define WRITE 1

int			ft_echo(t_built *built);
int			ft_cd(t_built *built, t_list *env_list);
int			ft_pwd(t_built *built);

#endif