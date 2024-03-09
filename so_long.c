/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:17:07 by mamir             #+#    #+#             */
/*   Updated: 2024/03/05 19:17:09 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_components(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

void	check_first_last_line(t_data *data, char *path)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (i < data->map_dim[1])
	{
	}
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

int	ft_countline(char *path)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	map_loop(t_data *data, char *path)
{
	int		i;
	int		j;
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	data.map_dim[0] = ft_countline(av[1]);
	data.map = (char **)malloc(sizeof(char *) * (data.map_dim[0] + 1));
	map_loop(&data, av[1]);
	check_rectangular(av[1]);
	check_sides(&data, av[1]);
	check_valid_components(av[1], &data);
	check_first_last_line(av[1], &data);
}
