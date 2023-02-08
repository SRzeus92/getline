/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapuano <srapuano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:36:18 by srapuano          #+#    #+#             */
/*   Updated: 2023/02/08 21:40:38 by srapuano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *line)
{
	char	*buff;
	int		i;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 1;
	while (!(ft_strchr(line, '\n')) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*ft_clean(char *line)
{
	size_t	i;
	char	*clean;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	clean = malloc((i + 2) * sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		clean[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		clean[i] = '\n';
		i++;
	}
	clean[i] = '\0';
	return (clean);
}

char	*ft_dirt(char *line)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	while (line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	dst = malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	j = 0;
	while (line[i + j] != '\0' && j < ft_strlen(line) - i)
	{
		dst[j] = line[i + j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, line);
	final = ft_clean(line);
	line = ft_dirt(line);
	return (final);
}
