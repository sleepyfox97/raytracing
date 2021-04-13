#include "./test.h"




int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int i;
	int j;
	t_cam	cam;
	t_sp	sp;

	cam.p_cam.x = 0;
	cam.p_cam.y = 0;
	cam.p_cam.z = 0;
	cam.r_cam.x = 1;
	cam.r_cam.y = 0;
	cam.r_cam.z = 0;
	cam.r_cam = ft_make_nomalvec(cam.r_cam);
	cam.fov = M_PI / 4;
	sp.sp_c.x = 1;
	sp.sp_c.y = 0;
	sp.sp_c.z = 0;
	sp.r = 30;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "test");
	i = 0;
	cam = ft_screan_base(cam);
	while (i < 400) 
	{
		j = 0;
		while (j < 400)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, make_sphere(cam, sp, i, j, 500));
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
}


