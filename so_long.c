/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:17:07 by mamir             #+#    #+#             */
/*   Updated: 2024/05/05 19:29:29 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(2, "Invalid map!", 13);
	exit(1);
}

int	check_components(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

void	ft_pce(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_dim[0])
	{
		j = 0;
		while (j < data->map_dim[1])
		{
			if (data->map[i][j] == 'P')
				data->p++;
			if (data->map[i][j] == 'C')
				data->c++;
			if (data->map[i][j] == 'E')
				data->e++;
			j++;
		}
		i++;
	}
	if (data->p != 1 || data->c < 1 || data->e != 1)
	{
		write(2, "Map compenents error\n", 22);
		exit(1);
	}
}

void	check_first_last_line(char *path, t_data *data)
{
	variables var;
	char	*str;	

	var.fd = open(path, O_RDONLY);
	var.i = 0;
	str = get_next_line(var.fd);
	while (str[var.i] != '\n')
	{
		if (str[var.i] != '1')
			ft_error();
		var.i++;
	}
	var.i = 0;
	while (str != NULL)
	{
		var.j = 0;
		if (var.i == data->map_dim[0] - 1)
		{
			while (str[var.j] != '\0')
			{
				if (str[var.j] != '1')
					ft_error();
				var.j++;
			}
		}
		str = get_next_line(var.fd);
		var.i++;
	}
	close(var.fd);
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

void	map_loop(t_data *data, char *path)
{
	char	*str;
	variables var;
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

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Invalid Map\n");
		exit(1);
	}
	if (ac != 2)
	{
		printf("arguments error\n");
		exit(1);
	}
	data.px = 0;
	data.py = 0;
	data.map_dim[0] = ft_countline(av[1]);
	data.map = (char **)malloc(sizeof(char *) * (data.map_dim[0] + 1));
	map_loop(&data, av[1]);
	check_rectangular(av[1]);
	check_first_last_line(av[1], &data);
	check_sides(&data, av[1]);
	check_valid_components(av[1], &data);
	ft_pce(&data);
	ft_player_position(&data);
	ft_start_game(&data);
}
