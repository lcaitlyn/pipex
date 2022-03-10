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


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(const char *s);
char	*ft_strnstr(const char *s1, const char *s2, int n);
char	**ft_split(char const *s, char c);
void	*ft_calloc(int count, int size);
char	**ft_split(char const *s, char c);
void	*ft_bzero(void *src, size_t b);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_free_split(char **arr, int j);

