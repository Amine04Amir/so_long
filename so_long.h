/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:17:25 by mamir             #+#    #+#             */
/*   Updated: 2024/05/05 15:27:47 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct s_data
{
	int		map_dim[2];
	char	**map;
	int		p;
	int		c;
	int		e;
	void	*mlx;
	void	*win;
	void	*img;
	void	*floor;
	void	*wall;
	void	*player;
	void	*colectible;
	void	*exit;
	void	*open;
	int		width;
	int		height;
	int		px;
	int		py;
	int		moves;
}			t_data;

void		ft_put_textures(t_data *data);
void		ft_init_textures(t_data *data);
void		ft_start_game(t_data *data);
void		ft_player_position(t_data *data);

#endif
