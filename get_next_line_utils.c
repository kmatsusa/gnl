/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa <kmatsusa@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:50:22 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/03/06 06:16:40 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strchr(char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void		ft_strcpy(char *s1, char *s2, size_t n)
{
	while (n--)
		s1[n] = s2[n];
}

char		*ft_strdup(char *s1)
{
	size_t	n;
	char	*p;

	n = ft_strlen(s1);
	p = (char *)malloc(n + 1);
	if (p == NULL)
		return (NULL);
	p[n] = 0;
	ft_strcpy(p, s1, n);
	return (p);
}

char		*ft_strjoin(char *s1, char *s2, ssize_t n1, ssize_t n2)
{
	char *p;

	if (n1 == -1)
		n1 = ft_strlen(s1);
	p = (char *)malloc(n1 + n2 + 1);
	if (p == NULL)
		return (NULL);
	ft_strcpy(p, s1, n1);
	ft_strcpy(p + n1, s2, n2);
	p[n1 + n2] = 0;
	return (p);
}
