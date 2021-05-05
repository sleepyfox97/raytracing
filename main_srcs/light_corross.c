#include "./miniRT.h"

int	ft_iscross(t_gob *ob, t_light *l, t_cam *cam)
{
	int i;
	int tmp;

	i = 0;
	tmp = ob->obnum;
	while (1)
	{
		ob = ob->next;
		if (ob->obnum == tmp || i == 1)
			break;
		if (ob->type == 1)
			i = iscross_sp(ob, l->p, cam);
		else if (ob->type == 2)
			i = iscross_pl(ob, l->p, cam);
		// else if (ob->type == 3)
		// 	i = iscross_sq(ob, l->p, cam);
		// else if (ob->type == 4)
		// 	i = iscross_tr(ob, l->p, cam);
		// else if (ob->type == 5)
		// 	i = iscross_cy(ob, l->p, cam);
	}
	return (i);
}

int iscross_sp(t_gob *sp, t_vec3 lp, t_cam *cam)
{
	t_vec3	tmp1;
	t_vec3	tmp2;
	double	a;
	double	b;
	double	c;

	//rayと物体のぶつかる場所の座標
	tmp1 = ft_linear_transform(cam->vray, cam->p, cam->distance, 1);
	//上で出した座標からlightへの方向ベクトル
	tmp2 = ft_linear_transform(lp, tmp1, 1, -1);
	//tmp1の場所から，今注目してる球の中心の座標を引いたベクトル
	tmp1 = ft_linear_transform(tmp1, sp->p1, 1, -1);
	a = ft_v_d_len(tmp2);
	b = ft_inner_product(tmp1, tmp2);
	c = ft_v_d_len(tmp1) - sp->d * sp->d / 4;
	if(ft_quadratic_func(a, b, c) < INFINITY)
		return (1);
	else
		return (0);
}

//怪しいので，後で確認入れた方がいいかもしれん．
int	iscross_pl(t_gob *pl, t_vec3 lp, t_cam *cam)
{
	t_vec3	tmp1;
	t_vec3	tmp2;
	double	a;
	double	b;
	double	c;

	//rayと物体のぶつかる場所
	tmp1 = ft_linear_transform(cam->vray, cam->p, cam->distance, 1);
	c = ft_inner_product(cam->vray, pl->vno);
	if (c < 0)
		pl->vno = ft_linear_transform(pl->vno, pl->vno, -1, 0);
	//tmp1の場所からlightへの方向ベクトル
	tmp2 = ft_linear_transform(lp, tmp1, 1, -1);
	tmp2 = ft_make_unitvec(tmp2);
	a = ft_inner_product(tmp2, pl->vno);
	b = ft_inner_product(ft_linear_transform(tmp1, pl->p1, 1, -1), pl->vno);
	if (a == 0 || b / a > 0)
		return (0);
	return (1);
}
