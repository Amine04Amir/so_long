#include "so_long.h"


int all_collected(t_data *data)
{
    int i,j;
    int c;
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
void ft_put_textures(t_data *data)
{
    int i,j;

    ft_init_textures(data);
    i = 0;
    while (i < data->map_dim[0])
    {
        j = 0;
        while (j < data->map_dim[1])
        {
            mlx_put_image_to_window(data->mlx, data->win, data->floor, j*45, i*45);
            if (data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->colectible, j*45, i*45);
            if (data->map[i][j] == 'E')
            {
                if(all_collected(data))
                    mlx_put_image_to_window(data->mlx, data->win, data->open, j*45, i*45);
                else
                    mlx_put_image_to_window(data->mlx, data->win, data->exit, j*45, i*45);
            }
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall, j*45, i*45);
            if (data->map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->player, j*45, i*45);
            j++;
        }
        i++;
    }
}

void ft_init_textures(t_data *data)
{
    data->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm", &data->width, &data->height);
    data->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->width, &data->height);
    data->player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &data->width, &data->height);
    data->colectible = mlx_xpm_file_to_image(data->mlx, "./textures/colectible.xpm", &data->width, &data->height);
    data->exit = mlx_xpm_file_to_image(data->mlx, "./textures/door.xpm", &data->width, &data->height);
    data->open = mlx_xpm_file_to_image(data->mlx, "./textures/door2.xpm", &data->width, &data->height);
}
void ft_player_position(t_data *data)
{
    int i,j;

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
            j++;
        }
        i++;
    }
}

void ft_move_right(t_data *data)
{
    int px = data->px;
    int py = data->py;

    if ((data->map[py][px + 1] != '1') && (data->map[py][px + 1] != 'E'))
    {
        data->map[py][px] = '0';
        data->map[py][px + 1] = 'P';
        ft_player_position(data);
        data->moves++;
        printf("moves: %d\n", data->moves);
    }
}
void    ft_move_left(t_data *data)
{
    int px = data->px;
    int py = data->py;

    if ((data->map[py][px - 1] != '1') && (data->map[py][px - 1] != 'E'))
    {
        data->map[py][px] = '0';
        data->map[py][px - 1] = 'P';
        ft_player_position(data);
        data->moves++;
        printf("moves: %d\n", data->moves);
    }
}

void ft_move_up(t_data *data)
{
    int px = data->px;
    int py = data->py;

    if ((data->map[py - 1][px] != '1') && (data->map[py - 1][px] != 'E'))
    {
        data->map[py][px] = '0';
        data->map[py - 1][px] = 'P';
        ft_player_position(data);
        data->moves++;
        printf("moves: %d\n", data->moves);
    }
}

void    ft_move_down(t_data *data)
{
    int px = data->px;
    int py = data->py;

    if ((data->map[py + 1][px] != '1') && (data->map[py + 1][px] != 'E'))
    {
        data->map[py][px] = '0';
        data->map[py + 1][px] = 'P';
        ft_player_position(data);
        data->moves++;
        printf("moves: %d\n", data->moves);
    }
}


int ft_move_player(int keycode,t_data *data)
{
    if (keycode == 13) // up
    {
        ft_move_up(data);
        mlx_clear_window(data->mlx,data->win);
        ft_put_textures(data);
    } 
    if (keycode == 2) // right
    {
        ft_move_right(data);
        mlx_clear_window(data->mlx,data->win);
        ft_put_textures(data);
    }
    if (keycode == 1) // down
    {
        ft_move_down(data);
        mlx_clear_window(data->mlx,data->win);
        ft_put_textures(data);
    }
    if (keycode == 0) // left
    {
        ft_move_left(data);
        mlx_clear_window(data->mlx,data->win);
        ft_put_textures(data);
    }
    return(0);
}

void ft_start_game(t_data *data)
{
    data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_dim[1] * 45, data->map_dim[0] * 45, "so_long");
    ft_put_textures(data);
    data->moves = 0;
    printf("moves: %d\n", data->moves);
    mlx_hook(data->win, 02, 0, ft_move_player, data);
	mlx_loop(data->mlx);
}
