/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:17:25 by mamir             #+#    #+#             */
/*   Updated: 2024/05/05 20:07:37 by mamir            ###   ########.fr       */
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
	int		ex;
	int		ey;
	int		moves;
}			t_data;

typedef struct s_var
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		fd;
}			t_var;

void		ft_put_textures(t_data *data);
void		ft_init_textures(t_data *data);
void		ft_start_game(t_data *data);
void		ft_player_position(t_data *data);
void		map_loop(t_data *data, char *path);
void		check_rectangular(char *path);
void		check_valid_components(char *path, t_data *data);
void		check_sides(t_data *data, char *path);
void		while_check(t_data *data, char *str, char *path);
void		check_first_last_line(char *path, t_data *data);
void		ft_error(void);
int			check_components(char c);
#endif
