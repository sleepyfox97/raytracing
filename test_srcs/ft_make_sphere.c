#include "./ft_test.h"

int		make_sphere(t_cam cam, t_sp sp, double x, double y)
{
	double	a;
	double	b;
	double	c;
	t_vec3	v_ray;
	t_vec3	tmp;

	tmp = ft_linear_transform(cam.p_cam, sp.sp_c, 1, -1);
	v_ray = ft_make_ray(cam, x , y);
	a = ft_v_d_len(v_ray);
	b = ft_inner_product(v_ray, tmp);
	c = ft_v_d_len(tmp) - sp.r * sp.r;
	//printf("%lf\n", b * b - 4 * a * c);
	if (b * b -  a * c >= 0)
		return (120);
	return (0);
}

int main()
{
	int i;
	int j;
	t_cam	cam;
	t_sp	sp;

	cam.p_cam.x = -1;
	cam.p_cam.y = 0;
	cam.p_cam.z = 0;
	cam.r_cam.x = 1;
	cam.r_cam.y = 0.2;
	cam.r_cam.z = -0.2;
	cam.r_cam = ft_make_unitvec(cam.r_cam);
	cam.fov = M_PI / 4;
	cam.p_to_sc = ft_linear_transform(cam.r_cam, cam.r_cam, (500 / (2 * tan(cam.fov / 2))), 0);
	sp.sp_c.x = 100;
	sp.sp_c.y = 0;
	sp.sp_c.z = 0;
	sp.r = 30;


	void *mlx_ptr;
	void *win_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");

	i = 0;
	cam = ft_make_screan_base(cam);
	while (i <= 500)
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, make_sphere(cam, sp, i - 250, j - 250));
			j++;
		}
		i++;
	}
		mlx_loop(mlx_ptr);
}
