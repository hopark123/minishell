#include "head.h"

int	check_file_exist(char *name)
{
	struct stat	sb;

	return (stat(name, &sb));
}

static char	*choose_bin(char *str1, char *str2, char *str3)
{
	if (check_file_exist(str1) == -1)
	{
		free(str1);
		if (check_file_exist(str2) == -1)
		{
			free(str2);
			if (check_file_exist(str3) == -1)
			{
				//실행파일 없음 에러.
				return (0);
			}
			return (str3);
		}
		free(str3);
		return (str2);
	}
	free(str2);
	free(str3);
	return (str1);
}

static char	**change_content(char **str)
{
	char	*tmp;
	char	*join;
	int	i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i][0] == '~')
		{
			join = getenv("HOME");
			tmp = ft_strjoin(join, &str[i][1]);
			free(str[i]);
			free(join);
			str[i] = tmp;
		}
		i++;
	}
	tmp = str[0];
	str[0] = choose_bin(ft_strjoin("/bin/", tmp), ft_strjoin("/usr/bin/", tmp), ft_strndup(tmp, ft_strlen(tmp)));
	free(tmp);
	return (str);
}

int	ft_execve(t_built *built, t_list *env_list)
{
	pid_t	pid;
	pid_t	w_pid;
	int	status;
	char	**argv;
	char	**envp;
	int		t_pip[2];
	
	ft_del_blank3(built);
	argv = change_content(ft_listtochar(built->command));
	envp = ft_listtochar(env_list);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		dup2(g_mini.pip[0], STDIN);
		status = execve(argv[0], argv, envp);
		if (status < 0)
		{
			perror("error");
			return (-1);
		}
	}
	else
	{
		dup2(g_mini.pip[1], STDOUT);
		w_pid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			w_pid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
