#include "./ft_test.h"


int main()
{
	int i;
	int j;
	t_cam	cam;
	t_sp	sp;
	t_light	light;

	int width = 700;
	int hight = 700;

	cam.p_cam.x = 0;
	cam.p_cam.y = 0;
	cam.p_cam.z = 0;
	cam.r_cam.x = 1;
	cam.r_cam.y = 0;
	cam.r_cam.z = 0;
	cam.r_cam = ft_make_unitvec(cam.r_cam);
	cam.fov = M_PI / 4;
	cam.p_to_sc = ft_linear_transform(cam.r_cam, cam.r_cam, ((double)width / (2 * tan(cam.fov / 2))), 0);
	sp.sp_c.x = 100;
	sp.sp_c.y = 0;
	sp.sp_c.z = 0;
	sp.r = 30;
	sp.color = (195 << 16) + (85 << 8) + (200);

	light.l_p.x = 70;
	light.l_p.y = 10;
	light.l_p.z = 200;

	double	*t = (double *)malloc(sizeof(double) * (width * hight));
	int		*color = (int *)malloc(sizeof(int) * (width * hight));

	void *mlx_ptr;
	void *win_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, hight, "test");

	//カメラの初期設定ゾーン
	cam = ft_make_screan_base(cam);

	//lightの初期設定ゾーン
	light.r = 0.9;
	light.c_to_l = ft_linear_transform(light.l_p, sp.sp_c, 1, -1);
	light.c_to_l = ft_make_unitvec(light.c_to_l);
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < hight)
		{
			color[i * hight + j] = make_sphere(&cam, sp, i - width / 2, (-1)*(j - hight / 2), &(t[i * hight + j]));
			ft_put_vector(cam.v_ray);
			color[i * hight + j] = ft_diffuse_reflection(cam, light, t[i * hight + j], color[i * hight + j]);
			j++;
		}
		i++;
	}
	//ft_diffuse_reflection(cam, t, l); //本来は，lightに関して回さないといけないので注意
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < hight)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, color[i * hight + j]);
			j++;
		}
		i++;
	}
		mlx_loop(mlx_ptr);
}




// int main()
// {
// 	void *mlx_ptr;
// 	void *win_ptr;
// 	int i;
// 	int j;
// 	t_cam	cam;
// 	t_sp	sp;

// 	cam.p_cam.x = 0;
// 	cam.p_cam.y = 0;
// 	cam.p_cam.z = 0;
// 	cam.r_cam.x = 1;
// 	cam.r_cam.y = 1;
// 	cam.r_cam.z = 1;
// 	cam.r_cam = ft_make_nomalvec(cam.r_cam);
// 	cam.fov = M_PI / 4;
// 	sp.sp_c.x = 1;
// 	sp.sp_c.y = 1;
// 	sp.sp_c.z = 1;
// 	sp.r = 30;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
// 	i = 1;
// 	cam = ft_screan_base(cam);
// 	while (i < 501)
// 	{
// 		j = 1;
// 		while (j < 501)
// 		{
// 			mlx_pixel_put(mlx_ptr, win_ptr, i, j, make_sphere(cam, sp, (double)i, (double)j));
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_loop(mlx_ptr);
// }


