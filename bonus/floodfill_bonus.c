/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:32 by mamir             #+#    #+#             */
/*   Updated: 2024/05/10 11:46:25 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_copie(t_data *data, char *path, char **copie)
{
	int		i;
	int		j;
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (i < data->map_dim[0])
	{
		j = 0;
		copie[i] = (char *)malloc(sizeof(char) * (data->map_dim[1] + 1));
		if (!copie[i])
			ft_error("malloc !\n");
		while (j < data->map_dim[1])
		{
			copie[i][j] = str[j];
			j++;
		}
		free(str);
		str = get_next_line(fd);
		copie[i][j] = '\0';
		i++;
	}
}

void	ft_free(t_data *data, char **str)
{
	int	i;

	i = 0;
	while (i < data->map_dim[0])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_duplicate(t_data *data, char *path)
{
	int		i;
	int		j;
	char	**copie;

	copie = (char **)malloc(sizeof(char *) * (data->map_dim[0]));
	if (!copie)
		ft_error("Copied map!\n");
	ft_copie(data, path, copie);
	ft_player_position(data);
	flood_fill(data, copie, data->px, data->py);
	i = 0;
	while (i < data->map_dim[0])
	{
		j = 0;
		while (j < data->map_dim[1])
		{
			if (copie[i][j] == 'E' || copie[i][j] == 'C')
				ft_error("Flood Fill!\n");
			j++;
		}
		i++;
	}
	ft_free(data, copie);
}

void	flood_fill(t_data *data, char **copie, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_dim[0] || y >= data->map_dim[1])
		ft_error("out of borders\n");
	if (copie[x][y] == 'E')
		copie[x][y] = '1';
	if (copie[x][y] == 'C' || copie[x][y] == 'E' || copie[x][y] == '0'
		|| copie[x][y] == 'P')
	{
		copie[x][y] = '.';
		flood_fill(data, copie, x + 1, y);
		flood_fill(data, copie, x - 1, y);
		flood_fill(data, copie, x, y + 1);
		flood_fill(data, copie, x, y - 1);
	}
}
