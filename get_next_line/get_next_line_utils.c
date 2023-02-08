/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:36:20 by srapuano          #+#    #+#             */
/*   Updated: 2023/02/08 21:17:49 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buff)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!buff)
		return (NULL);
	if (!line)
	{
		line = malloc(sizeof(char));
		line[0] = '\0';
	}
	dst = malloc((ft_strlen(line) + ft_strlen(buff) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i] != 0)
	{
		dst[i] = line[i];
		i++;
	}
	while (buff[j] != 0)
		dst[i++] = buff[j++];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
