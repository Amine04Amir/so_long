/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamir <mamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:17:25 by mamir             #+#    #+#             */
/*   Updated: 2024/05/15 15:57:52 by mamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "mlx.h"
#include <stdio.h>

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
	size_t	moves;
}			t_data;

void		ft_put_textures(t_data *data);
void		ft_init_textures(t_data *data);
void		ft_start_game(t_data *data);
int			ft_exit(t_data *data);
void		ft_put_exit(t_data *data);
void		check_xpm(void *img);

void		map_loop(t_data *data, char *path);
void		check_rectangular(char *path);
void		check_sides(t_data *data, char *path);
void		check_valid_components(char *path, t_data *data);
void		check_first_last_line(char *path, t_data *data);
void		ft_duplicate(t_data *data, char *path);
void		ft_copie(t_data *data, char *path, char **copie);
void		flood_fill(t_data *data, char **copie, int x, int y);

void		ft_player_position(t_data *data);
int			all_collected(t_data *data);
int			ft_keys(int keycode, t_data *data);

void		ft_move_right(t_data *data);
void		ft_move_left(t_data *data);
void		ft_move_up(t_data *data);
void		ft_move_down(t_data *data);
int			ft_right_left(int keycode, t_data *data);
int			ft_up_down(int keycode, t_data *data);

void		while_check(t_data *data, char *str, char *path);
void		ft_error(char *str);
char		*ft_strrchr(const char *str, int c);
int			check_components(char c);
void		check_extension(char *path);

#endif
