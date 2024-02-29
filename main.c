#include <mlx.h>
#include <stdlib.h>
# define WIDTH 1000
# define HEIGHT 500

int main()
{
    void    *mlx_cnx;
    void    *mlx_win;
    int i,j;

    i = HEIGHT * 0.1;
    mlx_cnx = mlx_init();
    mlx_win = mlx_new_window(mlx_cnx, WIDTH, HEIGHT , "So_long");
    while (i < HEIGHT * 0.9)
    {
        j = WIDTH * 0.1;
       while(j < WIDTH * 0.9)
       {
            mlx_pixel_put(mlx_cnx, mlx_win, j, i, rand() % 0x1000000);
            ++j;
       }
        ++i;
    }
    mlx_string_put(mlx_cnx, mlx_win, WIDTH * 0.8, HEIGHT * 0.93, 3950428, "Signal lost");
    mlx_loop(mlx_cnx);
    free(mlx_cnx);
}