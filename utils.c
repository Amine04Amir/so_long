/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:51:23 by mamir             #+#    #+#             */
/*   Updated: 2024/05/06 19:06:56 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	while_check(t_data *data, char *str, char *path)
{
	int	j;
	int	i;
	int	fd;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		j = 0;
		if (i == data->map_dim[0] - 1)
		{
			while (str[j] != '\0')
			{
				if (str[j] != '1')
					ft_error();
				j++;
			}
		}
		str = get_next_line(fd);
		i++;
	}
}
char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

void	check_extension(char *path)
{
	char *filename;
	filename = ft_strrchr(path, '/');
	if (filename == NULL)
		filename = path;
	else
		filename++;
	char *file_extension = ft_strrchr(filename, '.');
	if (file_extension == NULL || ft_strcmp(file_extension, ".ber") != 0
		|| ft_strlen(filename) <= 4)
		ft_error();
}