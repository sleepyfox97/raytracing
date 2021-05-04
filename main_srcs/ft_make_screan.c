#include "./miniRT.h"

void	ft_print_obj(t_minirt *minirt)
{
	int i;
	int j;
	double x;
	double y;
	t_gob	*tmp;

	tmp = minirt->firstgob;
	while (1)
	{
		i = 0;
		while (i < (int)minirt->width)
		{
			x = i - minirt->width / 2;
			j = 0;
			while (j < (int)minirt->hight)
			{
				minirt->firstgob = tmp;
				y = (-1) * (j - minirt->hight / 2);
				minirt->firstcam->image[i * (int)minirt->hight + j] = ft_calcu_color(minirt, x, y);
				j++;
			}
			i++;
		}
		if (minirt->firstcam->next->cnum == 1)
			break ;
		minirt->firstcam = minirt->firstcam->next;//この回し方は下手なきがする．
	}
}

int	ft_calcu_color(t_minirt *rt, double x, double y)
{
	int color;
	t_color	c;

	rt->firstcam->distance = INFINITY;
	rt->firstcam->vray = ft_make_ray(rt->firstcam, x, y);
	rt->firstcam->tmpcolor = ft_set_color(100, 100, 100);//ピクセルごとにtmpcolorを初期化しないと危険
	while (1)
	{
		if (rt->firstgob->type == 1)
			ft_sp_color(rt->firstgob, rt->firstcam ,rt->firstlight, rt->al);
		//else if (rt->firstgob->type == 2)
		if (rt->firstgob->next == NULL)
			break ;
		rt->firstgob = rt->firstgob->next;
	}
	c = rt->firstcam->tmpcolor;
	color = (int)c.r << 16 | (int)c.g << 8 | (int)c.b;
	return (color);
	//objectに関するwhile文の中で，light影の判定，重なり判定を行い，色を決定
}

	// while (rt->firstgob != NULL)
	// {
	// 	if (rt->firstgob->type == 1)
	// 		ft_sp_color(rt->firstgob, rt->firstcam ,rt->firstlight, rt->al);
	// 	rt->firstgob = rt->firstgob->next;
	// }

double	ft_sp_color(t_gob *sp, t_cam *cam, t_light *l, t_amblight al)
{
	double tmp1;
	sp->vctoc = ft_linear_transform(sp->p1, cam->p, -1, 1);//初期化の方でできると計算量減らせてかっこいい
	tmp1 = cam->distance;
	cam->distance = ft_make_sp(cam, sp);
	if (cam->distance < tmp1)
	{
		cam->tmpcolor = ft_ambient_light(cam->tmpcolor, al);
		ft_diffusion_light(cam, l, sp, sp->vctoc);
	}
	return (cam->distance);
}

double	ft_make_sp(t_cam *cam, t_gob *sp)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = 1;//vrayは常に大きさ1なので変わらない．
	b = ft_inner_product(cam->vray, sp->vctoc); //vrayに合わせて変わる
	c = ft_v_d_len(sp->vctoc) - sp->d * sp->d / 4;//変わらない
	d = b * b - a * c;
	if (d > 0)
	{
		cam->distance = (-1) * b -sqrt(d);
		if ((-1) * b - sqrt(d) > 0)
			cam->distance = ((-1) * b - sqrt(d));
		else if ((-1) * b + sqrt(d) <= 0)
			cam->distance = INFINITY;
		else
			cam->distance = ((-1) * b + sqrt(d));
	}
	else
		cam->distance = INFINITY;
	// if (cam->distance == INFINITY)
	// 	return (INFINITY);
		//cam->tmpcolor = ft_set_color(30, 30, 30);
	// else
	// 	cam->tmpcolor = sp->color;
	return (cam->distance);
}


	//RGBで判断して明るければ，OK
	//ここら辺上手に考えたら計算量減らせそう．
	//vは球の中心んからカメラへ向かうベクトルになってる

t_color	ft_ambient_light(t_color c_color, t_amblight a)
{
	c_color.r = a.color.r * a.r;
	c_color.g = a.color.g * a.r;
	c_color.b = a.color.b * a.r;
	return (c_color);
}

void 	ft_diffusion_light(t_cam *cam, t_light *l, t_gob *sp, t_vec3 v)
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
	double	cos1;
	double	cos2;

	v1 = ft_linear_transform(cam->vray, v, cam->distance, 1);//拡散点における法線ベクトル
	v1 = ft_make_unitvec(v1);
	v2 = ft_linear_transform(cam->vray, l->vctol, (-1) * cam->distance, 1);//拡散点からlightに向かう
	v2 = ft_make_unitvec(v2);
	cos1 = ft_inner_product(v1, v2);
	if (cos1 > 0)
		cam->tmpcolor = ft_set_diffuse_color2(cam->tmpcolor, l->color, sp->color, cos1 * l->r);

	v3 = ft_linear_transform(v1, v2, (-2) * cos1, 1);//向きに注意
	v3 = ft_make_unitvec(v3);
	cos2 = ft_inner_product(cam->vray, v3);
	if (cos2 > 0)
	{
		cos2 = pow(cos2, 10) * l->r * 0.4;//正の時に2乗しないとダメ．
		cam->tmpcolor = ft_set_diffuse_color2(cam->tmpcolor, l->color, sp->color, cos2);
	}
	return ;
}

// t_color	ft_set_diffuse_color1(t_color c_c, t_color l_c, t_color s_c, double cos)
// {
// 	t_color rgb;

// 	rgb.r = (s_c.r / 255) * (l_c.r / 255) * cos * 255;
// 	rgb.g = (s_c.g / 255) * (l_c.g / 255) * cos * 255;
// 	rgb.b = (s_c.b / 255) * (l_c.b / 255) * cos * 255;
// 	if (rgb.r > 255)
// 		rgb.r = 255;
// 	if (rgb.g > 255)
// 		rgb.g = 255;
// 	if (rgb.b > 255)
// 		rgb.b = 255;
// 	if (rgb.r > c_c.r)
// 		c_c.r = rgb.r;
// 	if (rgb.g > c_c.g)
// 		c_c.g = rgb.g;
// 	if (rgb.b > c_c.b)
// 		c_c.b = rgb.b;
// 	return (c_c);
// }

t_color	ft_set_diffuse_color2(t_color c_c, t_color l_c, t_color s_c, double cos)
{
	t_color rgb;

	rgb.r = (s_c.r / 255) * (l_c.r / 255) * cos * 255;
	rgb.g = (s_c.g / 255) * (l_c.g / 255) * cos * 255;
	rgb.b = (s_c.b / 255) * (l_c.b / 255) * cos * 255;
	c_c.r = rgb.r + c_c.r;
	if (c_c.r > 255)
		c_c.r = 255;
	c_c.g = rgb.g + c_c.g;
	if (c_c.g > 255)
		c_c.g = 255;
	c_c.b = rgb.b + c_c.b;
	if (c_c.b > 255)
		c_c.b = 255;
	// if (rgb.r > 255)
	// 	rgb.r = 255;
	// if (rgb.g > 255)
	// 	rgb.g = 255;
	// if (rgb.b > 255)
	// 	rgb.b = 255;
	// if (rgb.r > c_c.r)
	// 	c_c.r = rgb.r;
	// if (rgb.g > c_c.g)
	// 	c_c.g = rgb.g;
	// if (rgb.b > c_c.b)
	// 	c_c.b = rgb.b;
	return (c_c);
}
//ホントはif文いるけど，比べる対称が今は，以内から無しでOK
//光が，なぜか，平面において，点対称に逆の場所から中ってることになってる．

t_vec3	ft_make_ray(t_cam *cam, double x, double y)
{
	t_vec3	vray;
	t_vec3	vtmp;

	vtmp = ft_linear_transform(cam->vsb1, cam->vsb2, x, y);
	vray = ft_linear_transform(vtmp, cam->vptos, 1, 1);
	vray = ft_make_unitvec(vray);
	return (vray);
}


t_color ft_set_color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void	ft_show_image(t_minirt *minirt)
{
	int		i;
	int		j;
	int		*c;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, minirt->width, minirt->hight, "miniRT");
	c = minirt->firstcam->image;
	i = 0;
	while (i < minirt->width)
	{
		j = 0;
		while (j < minirt->hight)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, c[i * (int)minirt->hight + j]);
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
	return ;
}
// 照明が物体同士の間にある場合の処理


// 	vtmp = ft_linear_transform(cam->p, gob->p1, 1, -1);//球の中心からカメラへのベクトル（ここの外で計算しい）
// 	cam->vray = ft_make_ray(cam, x, y);//ft_make_sphereの外に描画時，最初にやることにする．

// //vrayは単位ベクトルにしておくことで，tが常に，長さとして使用可能になる．

// int	ft_make_sphere(t_cam *cam, t_gob *gob, t_vec vtmp)
// {
// 	double	a;
// 	double	b;
// 	double	c;
// 	double	d;

// 	a = ft_v_d_len(cam->vray);
// 	b = ft_inner_product(cam->ray, vtmp);
// 	c = ft_v_d_len(vtmp) - gob->d + gob->d / 4;//先に2で割っといて，半径にして計算量減らしてもよさそう
// 	d = b * b - a * c;
// 	if (d >= 0)
// 	{
// 		//球の色を出すべき，xｙとその時のcameraからのcam->tが分かる
// 		//ambient lightを用いて，RGBを比較して，色の更新
// 		//lightを用いて,RGBを比較して，色の更新(while文回して，全てのlightに関して行う)
// 		//
// 	}
// }


// int	ft_iscross_sphere(t_vec3 v1, t_gob *sphere, t_vec vtmp)
// {

// }

// int	ft_iscross_plane()
// int	ft_iscross_triangle()
// int	ft_iscross_cylinder()
// int	ft_iscross_square()

