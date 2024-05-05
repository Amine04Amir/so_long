/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:12:49 by mamir             #+#    #+#             */
/*   Updated: 2024/05/05 21:55:35 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int i, j;
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

void	ft_move_right(t_data *data)
{
	int	px;
	int	py;

	px = data->px;
	py = data->py;
	if (data->map[py][px + 1] == 'E' && all_collected(data))
	{
		data->moves++;
		printf("moves: %d\n", data->moves);
		printf("YOU WIN!\n");
		exit(0);
	}
	if ((data->map[py][px + 1] == '0') || (data->map[py][px + 1] == 'C'))
	{
		data->map[py][px] = '0';
		data->map[py][px + 1] = 'P';
		ft_player_position(data);
		data->moves++;
		printf("moves: %d\n", data->moves);
	}
}
void	ft_move_left(t_data *data)
{
	int	px;
	int	py;

	px = data->px;
	py = data->py;
	if (data->map[py][px - 1] == 'E' && all_collected(data))
	{
		data->moves++;
		printf("moves: %d\n", data->moves);
		printf("YOU WIN!\n");
		exit(0);
	}
	if ((data->map[py][px - 1] == '0') || (data->map[py][px - 1] == 'C'))
	{
		data->map[py][px] = '0';
		data->map[py][px - 1] = 'P';
		ft_player_position(data);
		data->moves++;
		printf("moves: %d\n", data->moves);
	}
}

void	ft_move_up(t_data *data)
{
	int	px;
	int	py;

	px = data->px;
	py = data->py;
	if (data->map[py - 1][px] == 'E' && all_collected(data))
	{
		data->moves++;
		printf("moves: %d\n", data->moves);
		printf("YOU WIN!\n");
		exit(0);
	}
	if ((data->map[py - 1][px] == '0') || (data->map[py - 1][px] == 'C'))
	{
		data->map[py][px] = '0';
		data->map[py - 1][px] = 'P';
		ft_player_position(data);
		data->moves++;
		printf("moves: %d\n", data->moves);
	}
}

void	ft_move_down(t_data *data)
{
	int	px;
	int	py;

	px = data->px;
	py = data->py;
	if (data->map[py + 1][px] == 'E' && all_collected(data))
	{
		data->moves++;
		printf("moves: %d\n", data->moves);
		printf("YOU WIN!\n");
		exit(0);
	}
	if ((data->map[py + 1][px] == '0') || (data->map[py + 1][px] == 'C'))
	{
		data->map[py][px] = '0';
		data->map[py + 1][px] = 'P';
		ft_player_position(data);
		data->moves++;
		printf("moves: %d\n", data->moves);
	}
}
int	ft_move_player(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		ft_move_up(data);
		mlx_clear_window(data->mlx, data->win);
		ft_put_textures(data);
	}
	if (keycode == 2)
	{
		ft_move_right(data);
		mlx_clear_window(data->mlx, data->win);
		ft_put_textures(data);
	}
	if (keycode == 1)
	{
		ft_move_down(data);
		mlx_clear_window(data->mlx, data->win);
		ft_put_textures(data);
	}
	if (keycode == 0)
	{
		ft_move_left(data);
		mlx_clear_window(data->mlx, data->win);
		ft_put_textures(data);
	}
	if (keycode == 53)
	{
		ft_exit(data);
	}
	return (0);
}



