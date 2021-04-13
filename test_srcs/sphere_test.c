#include <X11/Xlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <X11/extensions/XShm.h>
#include "./mlx_linux/mlx.h"
#include <math.h>




int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int i;
	int j;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	i = 0;
	while (i < 500) 
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j,  put_star(500, 500, i, j));
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
}


