/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:50:35 by mamir             #+#    #+#             */
/*   Updated: 2024/05/05 20:09:48 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_loop(t_data *data, char *path)
{
	char	*str;
	t_var	var;

	var.fd = open(path, O_RDONLY);
	if (var.fd < 0)
		ft_error();
	str = get_next_line(var.fd);
	if (str == NULL)
		ft_error();
	data->map_dim[1] = ft_strlen(str) - 1;
	var.i = 0;
	while (var.i < data->map_dim[0])
	{
		var.j = 0;
		data->map[var.i] = (char *)malloc(sizeof(char) * data->map_dim[1]);
		while (var.j < data->map_dim[1])
		{
			data->map[var.i][var.j] = str[var.j];
			var.j++;
		}
		str = get_next_line(var.fd);
		var.i++;
	}
	close(var.fd);
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
		{
			printf("Invalid map[rect]\n");
			exit(1);
		}
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
		{
			printf("Invalid map[sides]\n");
			exit(1);
		}
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
			{
				printf("Invalid map[components]\n");
				exit(1);
			}
			j++;
		}
		str = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	while_check(t_data *data, char *str, char *path)
{
	int j;
	int i;
	int fd;
	
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
void	check_first_last_line(char *path, t_data *data)
{
	int i;
	int fd;
	char	*str;

	fd = open(path, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			ft_error();
		i++;
	}
	i = 0;
	while_check(data, str, path);
	close(fd);
}