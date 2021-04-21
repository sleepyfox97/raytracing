#include "./ft_test.h"


//純粋にベクトル計算を間違えてそう．
//反射が起こるのは，rayと物体との交点においてである．
//ｖはカメラから球の中心へのベクトル．

int	ft_diffuse_reflection(t_cam cam, t_light light, const double t, int color, t_vec3 v)
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
	double	cos1; //変数名考え直す
	double	cos2;

	if (t == 0)
		return (color);
	v1 = ft_linear_transform(cam.v_ray, v, t, -1);//カメラから交点までのベクトルから，カメラから球の中心までのベクトルを引いてる
	v1 = ft_make_unitvec(v1);	//規格化
	//交点からlightへの単位ベクトルをつくる．
	v2 = ft_linear_transform(cam.v_ray, light.c_to_l, (-1) * t, 1);//カメラから，ライトまでのベクトルから，カメラから交点までのベクトルを引いてる
	v2 = ft_make_unitvec(v2);//規格化
	cos1 = ft_inner_product(v1, v2);
	if (cos1 < 0)
		return (0);
	//鏡面反射の実装
	v3 = ft_linear_transform(v1, v2, -2 * cos1, 1);
	v3 = ft_make_unitvec(v3);
	cos2 = ft_inner_product(v3, ft_make_unitvec(cam.v_ray));
	cos2 = pow(cos2, 10);//pow関数はmath.hの中にいる累乗を可能にする関数
	cos1 = ft_max(cos1, cos2) * light.r;
	color = ((ft_dr_r(color, light.color, cos1) << 16)| (ft_dr_r(color, light.color, cos1) << 8)| ft_dr_r(color, light.color, cos1));
	return ((int)color);
}

int	ft_dr_r(int color1, int lcolor, double cos)
{
	double r1;
	double r2;
	double	re_c;

	r1 = (double)ft_get_rgb(color1, 'r');
	r2 = (double)ft_get_rgb(lcolor, 'r');
	re_c = (r1 / 255) * (r1 / 255) * cos * 255;
	return ((int)re_c);
}

int	ft_dr_g(int color, int lcolor, double cos)
{
	double g1;
	double g2;
	double re_c;

	g1 = (double)ft_get_rgb(color, 'g');
	g2 = (double)ft_get_rgb(lcolor, 'g');
	re_c = (g1 / 255) * (g2 / 255) *cos * 255;
	return ((int)re_c);
}

int	ft_dr_b(int color, int lcolor, double cos)
{
	double b1;
	double b2;
	double re_c;

	b1 = (double)ft_get_rgb(color, 'b');
	b2 = (double)ft_get_rgb(lcolor, 'b');
	re_c = (b1 / 255)  * (b2 / 255) *cos * 255;
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

