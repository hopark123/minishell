#include "head.h"

int	check_file_exist(char *name)
{
	struct stat	sb;

	return (stat(name, &sb));
}

static char	*choose_bin(char *str1, char *str2)
{
	if (check_file_exist(str1) == -1)
	{
		free(str1);
		if (check_file_exist(str2) == -1)
		{
			free(str2);
			//실행파일 없음 에러.
			return (0);
		}
		return (str2);
	}
	free(str2);
	return (str1);
}

static char	*change_content(char *str, t_list *env_list, int index)
{
	char	*tmp;
	char	*join;
	int	size;
	
	size = ft_strlen(str);
	if (str[0] == '~')
	{
		join = ft_getenv(env_list, "HOME", 4);
		tmp = ft_strjoin(join, &str[1]);
		free(join);
	}
	else if (index == 0 && str[0] != '/' && str[0] != '.')
	{
		tmp = choose_bin(ft_strjoin("/bin/", str), ft_strjoin("/usr/bin/", str));
	}
	else
		tmp = ft_strndup(str, size);
	return (tmp);
}

static char	**del_space_square(char **list, t_list *env_list)
{
	int	i;
	int	j;
	char	**tmp;

	i = 0;
	j = 0;
	while (list[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (list[i])
	{
		if (list[i][0] != ' ')
		{
			tmp[j] = change_content(list[i], env_list, j);
			j++;
		}
		free(list[i++]);
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
		{
			// printf("argv[0] : [%s]\n",argv[0]);
			perror("error");
			return (-1);
		}
	}
	else
	{
		w_pid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			w_pid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
