/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:08:47 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/03 18:27:20 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static char	*judge_execfile(char *str)
{
	struct stat	sb;
	char		*command;

	if (!str)
		return (0);
	command = ft_strndup(str, ft_strlen(str));
	if (!command)
		ft_error("malloc error");
	if (stat(command, &sb) == -1)
		ft_perror(command, 0);
	else if (S_ISDIR(sb.st_mode))
		ft_perror(command, "is a Directory");
	else if (!(sb.st_mode & S_IEXEC))
		ft_perror(command, "Permission denied");
	else
		return (command);
	free(command);
	return (0);
}

static char	*judge_command(char *str)
{
	char		*bin;
	char		*ubin;
	struct stat	sb;

	if (!str)
		return (0);
	bin = ft_strjoin("/bin/", str);
	ubin = ft_strjoin("/usr/bin/", str);
	if (!bin || !ubin)
		ft_error("malloc error");
	if (stat(bin, &sb) == -1)
	{
		free(bin);
		if (stat(ubin, &sb) == -1)
		{
			free(ubin);
			ft_perror(str, "command not found");
			return (0);
		}
		return (ubin);
	}
	free(ubin);
	return (bin);
}

static char	**change_content(char **str)
{
	char	*tmp;
	char	*join;
	int		i;

	i = 0;
	join = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i][0] == '~')
		{
			tmp = ft_strjoin(getenv("HOME"), &str[i][1]);
			free(str[i]);
			str[i] = tmp;
		}
		i++;
	}
	tmp = str[0];
	if (ft_strchr(tmp, '/'))
		str[0] = judge_execfile(tmp);
	else
		str[0] = judge_command(tmp);
	free(tmp);
	return (str);
}

static void	make_arg(t_built *built, t_list *env_list, \
	char ***argv, char ***envp)
{
	ft_del_blank3(built);
	(*argv) = change_content(ft_listtochar(built->command));
	(*envp) = ft_env_listtochar(env_list);
}

int	ft_execve(t_built *built, t_list *env_list)
{
	int		status;
	char	**argv;
	char	**envp;

	status = 0;
	make_arg(built, env_list, &argv, &envp);
	g_mini.pid = fork();
	ft_proc_signal();
	if (g_mini.pid < 0)
		ft_error("fork error");
	else if (g_mini.pid == 0)
	{
		if (g_mini.pip[0] > 0)
			dup2(g_mini.pip[0], STDIN);
		if (execve(argv[0], argv, envp) < 0)
			ft_error("execve error");
	}
	else
	{
		if (g_mini.pip[1] > 0)
			dup2(g_mini.pip[1], STDOUT);
		ft_parent(g_mini.pid, &status);
	}
	ft_free2(argv, ft_strlen2(argv));
	ft_free2(envp, ft_strlen2(envp));
	return (ft_status_control(status));
}
