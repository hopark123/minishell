/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 05:46:50 by suhong            #+#    #+#             */
/*   Updated: 2021/06/28 17:46:56 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <head.h>

static void	ft_subshell2(int *tmp)
{
	pid_t	pid;
	int	fd[2];
	int	status;
	
	close(tmp[1]);
	if (pipe(fd) == -1)
	{
		perror("pipe error:");
		return ;
	}
		// write(2,"[",1);
		// ft_putnbr_fd(fd[0], 2, 0);
		// ft_putnbr_fd(fd[1], 2, 0);
		// write(2,"]",1);
	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
	}
	else if (pid == 0)
	{
		dup2(tmp[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("sort", "sort", NULL);
	}
	else
	{
		close(fd[1]);
		waitpid(pid, NULL, 0);
		close(tmp[0]);
		tmp[1] = fd[1];
		tmp[0] = fd[0];
		close(fd[1]);
	}
}

static void	ft_subshell3(int *tmp)
{
	pid_t	pid;
	int	fd[2];
	int	status;
	
	close(tmp[1]);
	if (pipe(fd) == -1)
	{
		perror("pipe error:");
		return ;
	}
	dup2(tmp[0], fd[0]);
	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
	}
	else if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_putstr_fd("@@@@\n", STDOUT_FILENO,0);
		close(fd[1]);
		close(fd[0]);
		execlp("grep", "grep", "ap", NULL);
	}
	else
	{
		close(tmp[0]);
		close(tmp[1]);
		waitpid(pid, NULL, 0);
		close(tmp[1]);
		tmp[1] = fd[1];
		tmp[0] = fd[0];
		close(fd[1]);
		// close(fd[0]);
	}
}

static void	ft_subshell4(int *tmp)
{
	pid_t	pid;
	int	fd[2];
	int	status;
	if (pipe(fd) == -1)
	{
		perror("pipe error:");
		return ;
	}
	dup2(tmp[0], fd[0]);
	close(tmp[1]);
	// close(tmp[0]);
	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
	}
	else if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
									// int i = 0;
									// char *line;
									// while (i < 3)
									// {
									// 	fprintf(stderr, "%d[",i++);
									// 	ft_putnbr_fd(get_next_line(fd[0], &line), 2, 0);
									// close(fd[1]);
									// 	fprintf(stderr, "%s]\n", line);
									// }
		// dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execlp("cat", "cat", "-e", NULL);
	}
	else
	{
		close(tmp[0]);
		waitpid(pid, NULL, 0);
		close(tmp[1]);
		tmp[1] = fd[1];
		tmp[0] = fd[0];
		close(fd[0]);
		close(fd[1]);
	}
}

int	main(void)
{
	int pipfd[2];

	if (pipe(pipfd) < 0)
		return (0);
	dup2(STDIN_FILENO, pipfd[0]);
									// int i = 0;
									// char *line;
									// while (i < 3)
									// {
									// 	fprintf(stderr, "%d[",i++);
									// 	ft_putnbr_fd(get_next_line(pipfd[0], &line), 2, 0);
									// 	fprintf(stderr, "%s]\n", line);
									// }
	close(pipfd[1]);
	ft_subshell2(&pipfd[0]);
				// write(2,"[",1);
				// ft_putnbr_fd(pipfd[0], 2, 0);
				// ft_putnbr_fd(pipfd[1], 2, 0);
				// write(2,"]",1);
	ft_subshell3(&pipfd[0]);
	ft_subshell4(&pipfd[0]);
	write(1,"end\n",4);
	return (0);
}
