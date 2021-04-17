#include "./ft_test.h"

int	ft_diffuse_reflection(t_cam cam, t_light light, const double t, int color)
{
	t_vec3	v_n;
	double	tmp; //変数名考え直す

	v_n = ft_linear_transform(cam.v_ray, cam.p_to_sc, t, -1);
	v_n = ft_make_unitvec(v_n);
	tmp = ft_inner_product(v_n, light.c_to_l);
	if (tmp < 0)
		return (color);
	color = (ft_dr_r(color, light, tmp) << 16)| (ft_dr_r(color, light, tmp) << 8)| ft_dr_r(color, light, tmp);
	return ((int)color);
}

int	ft_dr_r(int color, t_light light, double cos)
{
	double r1;
	double r2;
	double	re_c;

	r1 = (double)ft_get_rgb(color, 'r');
	r2 = (double)ft_get_rgb(light.color, 'r');
	re_c = (r1 / 255) * (r2 / 255) * cos * 255 * light.r ;
	return ((int)re_c);
}

int	ft_dr_g(int color, t_light light, double cos)
{
	double g1;
	double g2;
	double re_c;

	g1 = (double)ft_get_rgb(color, 'g');
	g2 = (double)ft_get_rgb(light.color, 'g');
	re_c = (g1 / 255) * (g2 / 255) * cos * 255 * light.r ;
	return ((int)re_c);
}

int	ft_dr_b(int color, t_light light, double cos)
{
	double b1;
	double b2;
	double re_c;

	b1 = (double)ft_get_rgb(color, 'g');
	b2 = (double)ft_get_rgb(light.color, 'g');
	re_c = (b1 / 255) * (b2 / 255) * cos * 255 * light.r;
	return ((int)re_c);
}


//RGBはintだけど，必要に応じてdoubleキャストして，扱うと良い．
//RGBそれぞれに関して，ビット演算して，変換する関数を作る．
// int	ft_r_(int color, double tmp)
// {
// 	int	rtmp;
// 	int r;

// 	rtmp = 255 << 16;
// 	r = (rtmp & color) >> 16;
// 	r = r * tmp;
// }

