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

void	writer(char *argv[], char *envp[], int *fd)
{
	int	f2;

	f2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (f2 == -1 || access(argv[4], W_OK) == -1)
		ft_perror(ERR_F2);
	if (dup2(fd[0], 0) == -1)
		ft_perror(ERR_DUP);
	if (dup2(f2, 1) == -1)
		ft_perror(ERR_F2);
	close(fd[1]);
	ft_exec(argv[3], envp);
}

void	reader(char *argv[], char *envp[], int *fd)
{
	int	f1;

	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		ft_perror(ERR_F1);
	f1 = open(argv[1], O_RDONLY);
	if (f1 == -1)
		ft_perror(ERR_F1);
	if (dup2(f1, 0) == -1)
		ft_perror(ERR_F1);
	close(f1);
	if (dup2(fd[1], 1) == -1)
		ft_perror(ERR_DUP);
	close(fd[1]);
	ft_exec(argv[2], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	id;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_perror(ERR_PIPE);
		id = fork();
		if (id == -1)
			ft_perror(ERR_FORK);
		if (id == 0)
			reader(argv, envp, fd);
		waitpid(id, 0, 0);
		if (id > 0)
			writer(argv, envp, fd);
		close (fd[0]);
		close (fd[1]);
		return (0);
	}
	ft_perror(ERR_ARGC);
}
