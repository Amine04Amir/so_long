#include "so_long.h"

void ft_init_textures(t_data *data)
{
    data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_dim[1] * 45, data->map_dim[0] * 45, "so_long");
    data->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm", &data->width, &data->height);
    data->player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &data->width, &data->height);
    data->colectible = mlx_xpm_file_to_image(data->mlx, "./textures/colectible.xpm", &data->width, &data->height);
    data->exit = mlx_xpm_file_to_image(data->mlx, "./textures/door.xpm", &data->width, &data->height);
    return ;
}
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
	mlx_loop(data->mlx);
    return;
}

void ft_movement(t_data *data)
{
    mlx_hook(data->win, )
}
