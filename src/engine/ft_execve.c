#include "head.h"


static char	*change_content(char *str, t_list *env_list)
{
	char	*tmp;
	int	size;
	
	size = ft_strlen(str);
	if (!ft_strncmp3("~", str, size))
		tmp = ft_getenv(env_list, "HOME", 4);
	else
	{
		tmp = ft_strndup(str, size);
	}
	return (tmp);
}

static char	**del_space_square(char **list, t_list *env_list)
{
	int	i;
	int	j;
	int	size;
	char	**tmp;

	i = 0;
	j = 0;
	size = 0;
	while (list[size])
		size++;
	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (0);
	while (list[i])
	{
		if (list[i][0] != ' ')
			tmp[j++] = change_content(list[i], env_list);
		free(list[i]);
		i++;
	}
	tmp[j] = 0;
	free(list);
	return (tmp);
}

int	ft_execve(t_built *built, t_list *env_list)
{
	pid_t	pid;
	pid_t	w_pid;
	int	status;
	char	**argv;
	char	**envp;
	
	argv = del_space_square(ft_listtochar(built->command), env_list);
	envp = ft_listtochar(env_list);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		if (execve(argv[0], argv, envp) < 0)
			return (-1);
	}
	else
	{
		w_pid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			w_pid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
