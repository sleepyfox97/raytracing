#include "./miniRT.h"

double	ft_sp_color(t_gob *sp, t_cam *cam, t_light *l, t_amblight al)
{
	double	tmp1;
	t_light	*tmp2;

	sp->vctoc = ft_linear_transform(sp->p1, cam->p, -1, 1);//初期化の方でできると計算量減らせてかっこいい
	tmp1 = cam->distance;
	tmp2 = l;
	cam->distance = ft_make_sp(cam, sp);
	if (cam->distance < tmp1)
		cam->tmpcolor = ft_ambient_light(cam->tmpcolor, al);
	while (l != NULL)
	{
		if (cam->distance < tmp1 && !ft_iscross(sp, l, cam))
			ft_diffusion_light(cam, l, sp, sp->vctoc);
		l = l->next;
	}
	l = tmp2;
	return (cam->distance);
}

double	ft_make_sp(t_cam *cam, t_gob *sp)
{
	double	a;
	double	b;
	double	c;

	a = 1;//vrayは常に大きさ1なので変わらない．
	b = ft_inner_product(cam->vray, sp->vctoc); //vrayに合わせて変わる
	c = ft_v_d_len(sp->vctoc) - sp->d * sp->d / 4;//変わらない
	cam->distance = ft_quadratic_func(a, b, c);
	return (cam->distance);
}