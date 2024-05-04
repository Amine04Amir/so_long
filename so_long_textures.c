#include "so_long.h"

void ft_put_floor(t_data *data)
{
    int i,j;
    
    data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_dim[1] * 45, data->map_dim[0] * 45, "so_long");
    data->floor = mlx_xpm_file_to_image(data->mlx, "./images/floor.xpm", &data->width, &data->height);
    data->player = mlx_xpm_file_to_image(data->mlx, "./images/hafozli9.xpm", &data->width, &data->height);
    data->colectible = mlx_xpm_file_to_image(data->mlx, "./images/mushroom.xpm", &data->width, &data->height);
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
            j++;
        }
        i++;
    }
	mlx_loop(data->mlx);
    return;
}
