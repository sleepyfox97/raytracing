#include "test.h"

int		make_sphere(t_cam cam, t_sp sp, int x, int y, int width, int hight)
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
	printf("%lf\n", b * b - 4 * a * c);
	if (b * b - 4 * a * c >= 0)
		return (120);
	return (0);
}
