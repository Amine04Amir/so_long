/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:12:49 by mamir             #+#    #+#             */
/*   Updated: 2024/05/10 11:46:22 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	all_collected(t_data *data)
{
	int	c;
	int	i;
	int	j;

	i = 0;
	c = 0;
	while (i < data->map_dim[0])
	{
		j = 0;
		while (j < data->map_dim[1])
		{
			if (data->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
		return (1);
	return (0);
}

void	ft_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->px = 0;
	data->py = 0;
	while (i < data->map_dim[0])
	{
		j = 0;
		while (j < data->map_dim[1])
		{
			if (data->map[i][j] == 'P')
			{
				data->px = j;
				data->py = i;
			}
			if (data->map[i][j] == 'E')
			{
				data->ex = j;
				data->ey = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_keys(int keycode, t_data *data)
{
	ft_right_left(keycode, data);
	ft_up_down(keycode, data);
	if (keycode == 53)
		ft_exit(data);
	return (0);
}

int	ft_right_left(int keycode, t_data *data)
{
	if (keycode == 2 || keycode == 124)
	{
		ft_move_right(data);
		mlx_clear_window(data->mlx, data->win);
		ft_put_textures(data);
	}
	if (keycode == 0 || keycode == 123)
	{
		ft_move_left(data);
		mlx_clear_window(data->mlx, data->win);
		ft_put_textures(data);
	}
	return (0);
}

int	ft_up_down(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 126)
	{
		ft_move_up(data);
		mlx_clear_window(data->mlx, data->win);
		ft_put_textures(data);
	}
	if (keycode == 1 || keycode == 125)
	{
		ft_move_down(data);
		mlx_clear_window(data->mlx, data->win);
		ft_put_textures(data);
	}
	return (0);
}
