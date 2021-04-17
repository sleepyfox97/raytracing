#include "./ft_test.h"

int	ft_diffuse_reflection(t_cam cam, t_light light, const double t, double color)
{
	t_vec3	v_n;
	double	tmp; //変数名考え直す

	v_n = ft_linear_transform(cam.v_ray, cam.p_to_sc, t, -1);
	v_n = ft_make_unitvec(v_n);
	tmp = ft_inner_product(v_n, light.c_to_l);
	if (tmp < 0)
		return (color);
	color = 
	return (color);
}

ft_dr_r(int color, t_light light, double cos)
{
	int r1;
	int r2;
	double	re_c
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

