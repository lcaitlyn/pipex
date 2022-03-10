/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:33:56 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/01 15:35:04 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void writer(char *argv[], char *envp[], int *fd)
{
	int i = 0;
	int f2;
	
	char 	**s;
	char	*s1;
	char 	**s2;
	
	f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	
	dup2(fd[0], 0);
	dup2(f2, 1);
	close(fd[1]);
	
	
	while (!(ft_strnstr(envp[i], "PATH=", 5)))
	{
		i++;
		if (envp[i] == NULL)
		{
			exit (-1);
		}
	}
	s = ft_split(envp[i] + 5, ':');
	i = -1;
	s2 = ft_split(argv[3], ' ');
	i = 0;
	while (s[i])
	{
		s1 = ft_strjoin(s[i], "/");
		s1 = ft_strjoin(s1, s2[0]);
		if (access(s1, F_OK) == 0)
		{
			execve(s1, s2, envp);
		}
		i++;
	}
}

void reader(char *argv[], char *envp[], int *fd)
{
	int i = 0;
	
	char 	**s;
	char	*s1;
	char 	**s2;
	int		f1;
	
	f1 = open(argv[1], O_RDONLY);
	dup2(f1, 0);
	close(f1);
	dup2(fd[1], 1);
	close(fd[1]);
	
	
	while (!(ft_strnstr(envp[i], "PATH=", 5)))
	{
		i++;
		if (envp[i] == NULL)
		{
			exit (-1);
		}
	}
	s = ft_split(envp[i] + 5, ':');
	i = -1;
	s2 = ft_split(argv[2], ' ');
	i = 0;
	while (s[i])
	{
		s1 = ft_strjoin(s[i], "/");
		s1 = ft_strjoin(s1, s2[0]);
		if (access(s1, F_OK) == 0)
		{
			execve(s1, s2, envp);
		}
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int 	fd[2];
	pid_t	id;
	
	if (argc == 5)
	{
		pipe(fd);
		id = fork();
		if (id == 0)
			reader(argv, envp, fd);
		waitpid(id, 0, 0);
		if (id > 0)
			writer(argv, envp, fd);
	}
	return (0);
}
