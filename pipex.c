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

int	main(int argc, char *argv[], char *envp[])
{
	int 	fd[2];
	pid_t	id;

	if (argc == 3)
	{
		
	}
	else
	{
		int i = 0;
			while (!(ft_strnstr(envp[i], "PATH=", 5)))
			{
				i++;
				if (envp[i] == NULL)
				{
					exit (-1);
				}
			}
			printf ("%s\n", envp[i]);
	}
	}*/
	return (0);
}
