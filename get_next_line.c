/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa <kmatsusa@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:41:46 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/03/10 18:38:02 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *memo, char **line)
{
	free(memo);
	memo = NULL;
	free(*line);
}

int		ft_put_line(char **line, char **memo, char *buf)
{
	int		flag;
	size_t	n;
	char	*temp;

	n = ft_strchr(buf, '\n');
	temp = ft_strjoin(*line, buf, -1, n);
	if (temp == NULL)
		return (-1);
	free(*line);
	*line = temp;
	temp = NULL;
	flag = 0;
	if (buf[n] == '\n')
	{
		temp = ft_strdup(buf + n + 1);
		if (temp == NULL)
			return (-1);
		flag = 1;
	}
	free(*memo);
	*memo = temp;
	return (flag);
}

int		get_next_line(int fd, char **line)
{
	int			flag;
	static char	*memo;
	char		*buf;
	ssize_t		n;

	if (line == NULL || !(*line = (char *)malloc(1)))
		return (-1);
	*line[0] = 0;
	flag = 0;
	if (memo)
		flag = ft_put_line(line, &memo, memo);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		flag = -1;
	while (flag == 0 && (n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = 0;
		flag = ft_put_line(line, &memo, buf);
	}
	if (n < 0)
		flag = -1;
	free(buf);
	if (flag == -1)
		ft_free(memo, line);
	return (flag);
}
