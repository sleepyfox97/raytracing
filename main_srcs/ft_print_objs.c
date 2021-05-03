#include "./miniRT.h"

t_cam	*ft_make_screan_base(t_cam *cam)
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
	else
		cam->vsb2 = ft_cross_product(cam->vsb1, cam->vd);
	cam->vsb1 = ft_make_unitvec(cam->vsb1);
	cam->vsb2 = ft_make_unitvec(cam->vsb2);
	return (cam);
}

int	ft_prepare_print(t_minirt *rt)
{
	t_gob *tmp;
	//windowサイズとvmの画面サイズを比較して，正しいサイズにwidthとhightを変更する関数用意
	//
	if (!ft_cam_prepare(rt->firstcam, rt->width, rt->hight))
		return (0);
	rt->firstlight->vctol = ft_linear_transform(rt->firstcam->p, rt->firstlight->p, -1, 1);
	//camera構造体をいい感じにfreeしてやる必要がある．
	
	
	//tmp = ft_oblstlast(minirt->firstgob);
	//tmp->next = minirt->firstgob;
	// 	else if (!ft_obj_prepare(minirt->firstgob))
	// 		return (0);
	//	obj_prepareは不要説あり
	return (1);
}

int	ft_cam_prepare(t_cam *firstcam, double width, double hight)
{
	t_cam	*tmp1;
	t_cam	*tmp2;
	int		i;

	tmp1 = firstcam;
	i = 1;
	while(firstcam != NULL)
	{
		firstcam->fov = firstcam->fov * M_PI / 180;
		firstcam->vptos = ft_linear_transform(firstcam->vd, firstcam->vd, (width / (2 * (tan(firstcam->fov / 2)))), 0);
		firstcam = ft_make_screan_base(firstcam);
		firstcam->cnum = i;
		//firstcam->distance = (double *)malloc(sizeof(double) * width * hight);
		firstcam->image = (int *)malloc(sizeof(int) * width * hight);
		if (firstcam->image == NULL)
			return (0);
		if (firstcam->next == NULL)
			tmp2 = firstcam;
		firstcam = firstcam->next;
		i++;
	}
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	return (1);
}

// int	ft_obj_prepare(t_gob *firstgob)
// {

// }