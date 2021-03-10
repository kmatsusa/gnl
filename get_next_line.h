/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa <kmatsusa@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:12:08 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/03/09 14:06:28 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

void	ft_free(char *memo, char **line);
int		ft_put_line(char **line, char **memo, char *buf);
int		get_next_line(int fd, char **line);
size_t	ft_strchr(char *s, char c);
void	ft_strcpy(char *s1, char *s2, size_t n);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2, ssize_t n1, ssize_t n2);

#endif
