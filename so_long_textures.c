#include "so_long.h"

void ft_put_floor(t_data *data)
{
    int i,j;
    int block = 60;
    
    data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_dim[1] * block, data->map_dim[0]
			* block, "so_long");
    i = 0;
    while (i < data->map_dim[0])
    {
        j = 0;
        while (j < data->map_dim[1])
        {
            if (data->map[i][j] == '1')
            {
                int x,y;
                x = data->map[i][j] * block + block / 2;
                y = data->map[i][j] * block + block / 2;
                mlx_pixel_put(data->mlx, data->win, x, y, 0x7E0315);
            }
            j++;
        }
        i++;
    }
	mlx_loop(data->mlx);
    return;
}