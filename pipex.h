/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:34:04 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/01 15:34:13 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define ERR_ARGC "Argc != 5"
# define ERR_PIPE "Error with pipe"
# define ERR_FORK "Error with fork"
# define ERR_F1 "Error with file1"
# define ERR_F2 "Error with file2"
# define ERR_DUP "Error with dup2"
# define ERR_EXEC "Error with exec"
# define ERR_PATH "Error: Ain't path"
# define ERR_DUP "Error with dup2"
# define ERR_NO_CMD "Error: Put command"
# define ERR_CMD "Error: No such command"

int		ft_strlen(const char *s);
char	*ft_strnstr(const char *s1, const char *s2, int n);
char	**ft_split(char const *s, char c);
void	*ft_calloc(int count, int size);
char	**ft_split(char const *s, char c);
void	*ft_bzero(void *src, size_t b);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_free_split(char **arr, int j);
void	ft_putstr(char *s);

void	ft_exec(char *argv, char *envp[]);
void	ft_perror(char *str);

#endif
