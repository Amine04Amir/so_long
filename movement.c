/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:02:24 by mamir             #+#    #+#             */
/*   Updated: 2024/05/07 16:10:02 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_data *data)
{
	int	px;
	int	py;

	px = data->px;
	py = data->py;
	if (data->map[py][px + 1] == 'E' && all_collected(data))
	{
		data->moves++;
		write(1, &data->moves, 2);
		write(1, "RA7MA LKAWNIA WINS!", 20);
		exit(0);
	}
	if ((data->map[py][px + 1] == '0') || (data->map[py][px + 1] == 'C'))
	{
		data->map[py][px] = '0';
		data->map[py][px + 1] = 'P';
		ft_player_position(data);
		data->moves++;
		write(1, &data->moves, 2);
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
		write(1, &data->moves, 2);
		write(1, "RA7MA LKAWNIA WINS!", 20);
		exit(0);
	}
	if ((data->map[py][px - 1] == '0') || (data->map[py][px - 1] == 'C'))
	{
		data->map[py][px] = '0';
		data->map[py][px - 1] = 'P';
		ft_player_position(data);
		data->moves++;
		write(1, &data->moves, 2);
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
		write(1, &data->moves, 2);
		write(1, "RA7MA LKAWNIA WINS!", 20);
		exit(0);
	}
	if ((data->map[py - 1][px] == '0') || (data->map[py - 1][px] == 'C'))
	{
		data->map[py][px] = '0';
		data->map[py - 1][px] = 'P';
		ft_player_position(data);
		data->moves++;
		write(1, &data->moves, 2);
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
		write(1, &data->moves, 2);
		write(1, "RA7MA LKAWNIA WINS!", 20);
		exit(0);
	}
	if ((data->map[py + 1][px] == '0') || (data->map[py + 1][px] == 'C'))
	{
		data->map[py][px] = '0';
		data->map[py + 1][px] = 'P';
		ft_player_position(data);
		data->moves++;
		write(1, &data->moves, 2);
	}
}
