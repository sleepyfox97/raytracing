#include "./ft_test.h"

int		make_sphere(t_cam cam, t_sp sp, double x, double y, double width, double hight)
{
	double	a;
	double	b;
	double	c;
	t_vec3	v_ray;
	t_vec3	tmp;

	tmp = ft_linear_transform(cam.p_cam, sp.sp_c, 1, -1);
	v_ray = ft_make_ray(cam, x , y, width, hight);
	a = ft_v_d_len(v_ray);
	b = ft_inner_product(v_ray, tmp);
	c = ft_v_d_len(tmp);
	//printf("%lf\n", b * b - 4 * a * c);
	if (b * b - 4 * a * c >= 0)
		return (120);
	return (0);
}

// int main()
// {
// 	int i;
// 	int j;
// 	t_cam	cam;
// 	t_sp	sp;

// 	cam.p_cam.x = 0;
// 	cam.p_cam.y = 0;
// 	cam.p_cam.z = 0;
// 	cam.r_cam.x = 1;
// 	cam.r_cam.y = 0;
// 	cam.r_cam.z = 0;
// 	cam.r_cam = ft_make_nomalvec(cam.r_cam);
// 	cam.fov = M_PI / 4;
// 	sp.sp_c.x = 1;
// 	sp.sp_c.y = 0;
// 	sp.sp_c.z = 0;
// 	sp.r = 30;

// 	i = 0;
// 	cam = ft_screan_base(cam);
// 	while (i < 500)
// 	{
// 		j = 0;
// 		while (j < 500)
// 		{
// 			make_sphere(cam, sp, i, j, 500, 500);
// 			j++;
// 		}
// 		i++;
// 	}
// }
