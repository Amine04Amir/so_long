/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:17:07 by mamir             #+#    #+#             */
/*   Updated: 2024/05/03 16:50:54 by mamir            ###   ########.fr       */
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
		printf("Compenents error");
		exit(1);
	}
}

void	check_first_last_line(char *path, t_data *data)
{
	int		fd;
	int		i;
	char	*str;
	int		j;

	fd = open(path, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str[i] != '\n')
	{
		if (str[i] != '1')
		{
			printf("Invalid map[star lwl]\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (str != NULL)
	{
		j = 0;
		if (i == data->map_dim[0] - 1)
		{
			while (str[j] != '\0')
			{
				if (str[j] != '1')
				{
					printf("Invalid map[str lkher]\n");
					exit(1);
				}
				j++;
			}
		}
		str = get_next_line(fd);
		i++;
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
	int		i;
	int		j;
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error();
	str = get_next_line(fd);
	if (str == NULL)
	{
		printf("khawi\n");
		exit(1);
	}
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
	data.map_dim[0] = ft_countline(av[1]);
	data.map = (char **)malloc(sizeof(char *) * (data.map_dim[0] + 1));
	map_loop(&data, av[1]);
	check_rectangular(av[1]);
	check_first_last_line(av[1], &data);
	check_sides(&data, av[1]);
	check_valid_components(av[1], &data);
	ft_pce(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.map_dim[1] * 50, data.map_dim[0]
			* 50, "so_long");
	mlx_string_put(data.mlx, data.win, 210, 76, 0xFFFFFF, "Counter");
	mlx_loop(data.mlx);
}
