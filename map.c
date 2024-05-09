/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:50:35 by mamir             #+#    #+#             */
/*   Updated: 2024/05/09 15:08:24 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_loop(t_data *data, char *path)
{
	int		i;
	int		j;
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	data->map_dim[1] = ft_strlen(str) - 1;
	i = 0;
	while (i < data->map_dim[0])
	{
		j = 0;
		data->map[i] = (char *)malloc(sizeof(char) * data->map_dim[1]);
		while (j < data->map_dim[1])
		{
			data->map[i][j] = str[j];
			j++;
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	check_rectangular(char *path)
{
	char	*str;
	size_t	len;
	int		fd;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	len = ft_strlen1(str);
	while (str != NULL)
	{
		if (ft_strlen1(str) != len)
			ft_error("map not rectangular\n");
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

void	check_sides(t_data *data, char *path)
{
	int		i;
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (i < data->map_dim[0] && str != NULL)
	{
		if (str[0] != '1' || str[data->map_dim[1] - 1] != '1')
			ft_error("Invalid Sides!\n");
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	check_valid_components(char *path, t_data *data)
{
	int		fd;
	int		i;
	int		j;
	char	*str;

	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while (i < data->map_dim[0])
	{
		j = 0;
		while (j < data->map_dim[1])
		{
			if (!check_components(str[j]))
				ft_error("Invalid components\n");
			j++;
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	check_first_last_line(char *path, t_data *data)
{
	char	*str;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			ft_error("first line or last line not 1\n");
		i++;
	}
	i = 0;
	while_check(data, str, path);
	free(str);
	close(fd);
}
