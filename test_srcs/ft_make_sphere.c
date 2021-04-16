#include "./ft_test.h"

int		make_sphere(t_cam *cam, t_sp sp, double x, double y, double *t)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec3	tmp;

	tmp = ft_linear_transform(cam->p_cam, sp.sp_c, 1, -1); //ここ以外で計算できる．
	cam->v_ray = ft_make_ray(*cam, x , y);
	a = ft_v_d_len(cam->v_ray);
	b = ft_inner_product(cam->v_ray, tmp);
	c = ft_v_d_len(tmp) - sp.r * sp.r; //ここ以外で計算できる．
	d = b * b - a * c;
	if (d >= 0)
	{
		*t = -b - sqrt(d);
		return (sp.color);
	}
	*t = 0;
	return (0);
}

