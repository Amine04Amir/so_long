/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:53:53 by mamir             #+#    #+#             */
/*   Updated: 2024/05/05 22:32:47 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_exit(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_dim[0])
	{
		j = 0;
		while (j < data->map_dim[1])
		{
			if (data->map[i][j] == 'E')
			{
				if (all_collected(data))
					mlx_put_image_to_window(data->mlx, data->win, data->open, j
						* 45, i * 45);
				else
					mlx_put_image_to_window(data->mlx, data->win, data->exit, j
						* 45, i * 45);
			}
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->colectible,
					j * 45, i * 45);
			j++;
		}
		i++;
	}
}

void	ft_put_textures(t_data *data)
{
	int	i;
	int	j;

	ft_init_textures(data);
	i = 0;
	while (i < data->map_dim[0])
	{
		j = 0;
		while (j < data->map_dim[1])
		{
			mlx_put_image_to_window(data->mlx, data->win, data->floor, j * 45, i
				* 45);
			ft_put_exit(data);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall, j
					* 45, i * 45);
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->player, j
					* 45, i * 45);
			j++;
		}
		i++;
	}
}

void	ft_init_textures(t_data *data)
{
	data->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm",
			&data->width, &data->height);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",
			&data->width, &data->height);
	data->player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm",
			&data->width, &data->height);
	data->colectible = mlx_xpm_file_to_image(data->mlx,
			"./textures/colectible.xpm",
			&data->width,
			&data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./textures/door.xpm",
			&data->width, &data->height);
	data->open = mlx_xpm_file_to_image(data->mlx, "./textures/door2.xpm",
			&data->width, &data->height);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	write(1, "Closed!\n", 9);
	exit(0);
}

void	ft_start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_dim[1] * 45,
			data->map_dim[0] * 45, "so_long");
	ft_put_textures(data);
	data->moves = 0;
	printf("moves: %d\n", data->moves);
	mlx_hook(data->win, 02, 0, ft_keys, data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
}
