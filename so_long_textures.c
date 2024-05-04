#include "so_long.h"

void ft_put_floor(t_data *data)
{
    int i,j;

    ft_init_textures(data);
    i = 0;
    while (i < data->map_dim[0])
    {
        j = 0;
        while (j < data->map_dim[1])
        {
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->floor, j*45, i*45);
            if (data->map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->player, j*45, i*45);
            if (data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->colectible, j*45, i*45);
            if (data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit, j*45, i*45);
            j++;
        }
        i++;
    }
}


void ft_init_textures(t_data *data)
{
    data->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm", &data->width, &data->height);
    data->player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &data->width, &data->height);
    data->colectible = mlx_xpm_file_to_image(data->mlx, "./textures/colectible.xpm", &data->width, &data->height);
    data->exit = mlx_xpm_file_to_image(data->mlx, "./textures/door.xpm", &data->width, &data->height);
    return ;
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
    printf("px:%d \t py:%d\n", data->px, data->py);
}

void ft_move_right(t_data *data)
{
    int px = data->px;
    int py = data->py;

    printf(" px = %d | py = %d\n", data->px, data->py);
    if (data->map[py][px + 1] != '1')
    {
        data->map[py][px] = '0';
        data->map[py][px + 1] = 'P';
    }
}
int ft_move_player(int keycode,t_data *data)
{
    
    // if (keycode == 13)// up
    // {

    // }
    // mlx_clear_window(data->mlx, data->mlx);
    if (keycode == 2) // right
    {
        printf(" 1px = %d | 1py = %d\n", data->px, data->py);

        ft_move_right(data);
        mlx_clear_window(data->mlx,data->win);
        ft_put_floor(data);
    }

    // if (keycode == 1) // down
    // {

    // }
    // if (keycode == 0) // left
    // {

    // }

    return(0);
}

void ft_start_game(t_data *data)
{
    data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_dim[1] * 45, data->map_dim[0] * 45, "so_long");
    ft_put_floor(data);
    mlx_hook(data->win, 02, 0, ft_move_player, data);
	mlx_loop(data->mlx);
}



// void ft_movement(t_data *data)
// {
//     int right = 2;
//     int left = 0;
//     mlx_hook(data->win, right, left, (void *)ft_move_player, &data);

// }
