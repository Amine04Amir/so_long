#include <mlx.h>
#include <stdlib.h>

int main()
{
    void *mlx_ptr;

    mlx_ptr = mlx_init();
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}