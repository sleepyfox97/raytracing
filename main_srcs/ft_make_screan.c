#include "./miniRT.h"

t_cam	ft_make_screan_base(t_cam *cam)
{
	if (cam->vd.x == 0 && cam->vd.y >= 0)
		cam->vsb1 = ft_set_vecele(1, 0, 0);
	else if (cam->vd.x == 0 && cam->vd.y < 0)
		cam->vsb1 = ft_set_vecele(-1, 0, 0);
	else if (cam->vd.y == 0 && cam->vd.x >= 0)
		cam->vsb1 = ft_set_vecele(0, -1 , 0);
	else if (cam->vd.y == 0 && cam->vd.x < 0)
		cam->vsb1 = ft_set_vecele(0, 1 , 0);
	else
	{
		cam->vsb1.x = 1;
		cam->vsb1.y = (-1) * (cam->vd.x + cam->vsb1.x) / cam->vd.y;
	}
	if (cam->vd.z == 0)
		cam->vsb2 = ft_set_vecele(0,0,1);
	else if
		cam->vsb2 = ft_cross_product(cam->vsb1, cam->vd);
	cam->vsb1 = ft_make_unitvec(cam->vsb1);
	cam->vsb2 = ft_make_unitvec(cam->vsb2);
	return (cam);
}


t_vec3	ft_make_ray(t_cam *cam, double x, double y)
{
	t_vec3	vray;
	t_vec3	vtmp;

	vtmp = ft_linear_transform(cam->vsb1, cam->vsb2, x, y);
	vray = ft_linear_transform(vtmp, cam->vptos, 1, 1);
	vray = ft_make_unitvec(vray);
	return (vray);
}

void	ft_print_obj(t_minirt *minirt)
{
	int i;
	int j;
	double x;
	double y;

	while (minirt->firstcam->next->cnum != 1)
	{
		if (minirt->firstgob->type == 1)
			minirt->firstgob->vctoc = ft_linear_transform(minirt->firstgob->p1, minirt->firstcam->p, -1, 1);
		i = 0;
		while (i < minirt->width)
		{
			x = i - minirt->width / 2;
			while (j < minirt->hight)
			{
				y = (-1) * (j - minirt->hight) / 2;
				ft_calcu_color(minirt, x, y);
				j++;
			}
			j++;
		}
		minirt->firstcam = minirt->firstcam->next;//この回し方は下手なきがする．
	}
}


int	ft_calcu_color(t_minirt *minirt, double x, double y)
{
	int color

	minitr->firstcam->vray = ft_makke_ray(minirt->firstcam, x, y);//単位ベクトルとしてray出てくる
	while (minirt->firstgob != NULL)
	{
		if (minirt->firstgob->type == 1)
			ft_sp_color(minirt->firstgob, minirt->firstcam ,minirt->firstlight, minirt.al);
	}

	color = cam->tmpcolor.r << 16 | cam->tmpcolor.g << 8 | cam->tmpcolor.b;
	retrun (color);
	//色が確定したら，colorにビット演算して，返す．
	//objにも番号振ったら管理楽かも？
	//objectに関するwhile文を回す，
	//objectに関するwhile文の中で，light影の判定，重なり判定を行い，色を決定
	//出力
}


int	ft_sp_color(t_gob *sp, t_cam *cam, t_light *light, t_amblight al)
{

	ft_make_sp(cam, sp);

	return ()
	//ft_al_light

	//ft_light

	//rayだすt出す
	//今までのtと比較．
	//交点のt出す，al用いて，色の更新．
	//lightについてwhile分回す
		//lightごとにvctolの計算，
		//その他の物体がlightまでに邪魔をしてるかの計算
		//lightによる拡散反射，鏡面反射の実装
		//RGBで判断して明るければ，OK
		//ここら辺上手に考えたら計算量減らせそう．
}

void	ft_make_sp(t_cam *cam, t_gob *sp)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = ft_v_d_len(cam->vray);
	b = ft_inner_product(cam->vray, sp->vctoc);
	c = ft_v_d_len(sp->vctoc) - sp.d * sp.d / 4;
	d = b * b - a * c;
	if (d >= 0)
	{
		if ((-1) * b >= sqrt(d))
			cam->distance = ((-1) * b - sqrt(d)) / a;
		else if (b <= sqrt(d))
			cam->distance = ((-1) * b + sqrt(d)) / a;
		else
			cam->distance = INFINITY;
	}
	if (d < 0 || cam->distance == INFINITY)
		cam->tmpcolor = ft_set_color(255, 255, 255);
	else
		cam->tmpcolor = sp->color;
}

void	ft_show_image(t_minirt *minirt)
{
	int i;
	int j;
	double *c;
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
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, c[i * minirt->hight + j]);
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

