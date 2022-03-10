/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:47:11 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/10 12:47:13 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_clear_paths(char *paths[])
{
	int	i;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
}

char	*ft_find_cmd(char *cmd, char *paths[])
{
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
		{
			ft_clear_paths(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_clear_paths(paths);
	return (NULL);
}

char	**ft_find_paths(char *envp[])
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	if (envp[i] == NULL)
		ft_perror(ERR_PATH);
	exit (0);
}

void	ft_exec(char *argv, char *envp[])
{
	char	*path;
	char	**cmd;

	if (ft_strlen(argv) == 0)
		ft_perror(ERR_NO_CMD);
	cmd = ft_split(argv, ' ');
	path = ft_find_cmd(cmd[0], ft_find_paths(envp));
	if (!path)
		ft_perror (ERR_CMD);
	if (execve(path, cmd, envp) == -1)
		ft_perror(ERR_EXEC);
}
