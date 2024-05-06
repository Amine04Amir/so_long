/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:17:07 by mamir             #+#    #+#             */
/*   Updated: 2024/05/06 19:08:10 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

void	ft_error(void)
{
	write(2, "Invalid!", 9);
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

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error();
	if (ac != 2)
		ft_error();
	check_extension(av[1]);
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
