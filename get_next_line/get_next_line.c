/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:47:04 by mamir             #+#    #+#             */
/*   Updated: 2024/02/17 11:47:06 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rest(char *statik)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (!statik)
		return (NULL);
	while (statik[i] != '\n' && statik[i] != '\0')
		i++;
	if (statik[i] == '\0')
	{
		free(statik);
		return (NULL);
	}
	rest = malloc(ft_strlen(statik) - i + 1);
	if (!rest)
		return (NULL);
	i++;
	while (statik[i])
		rest[j++] = statik[i++];
	rest[j] = '\0';
	free(statik);
	return (rest);
}

char	*ft_line(char *statik)
{
	int		i;
	char	*line;

	i = 0;
	if (!statik[i])
		return (NULL);
	while (statik[i] != '\n' && statik[i] != '\0')
		i++;
	if (statik[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (statik[i] != '\n' && statik[i] != '\0')
	{
		line[i] = statik[i];
		i++;
	}
	if (statik[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *statik)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read != 0 && !ft_strchr(statik, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(statik);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		statik = ft_strjoin(statik, buffer);
	}
	free(buffer);
	return (statik);
}

char	*get_next_line(int fd)
{
	static char	*statik;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	statik = ft_read(fd, statik);
	if (!statik)
		return (NULL);
	line = ft_line(statik);
	statik = ft_rest(statik);
	return (line);
}
