#include "./miniRT.h"

int	ft_prepare_print(t_minirt *minirt)
{
	//windowサイズとvmの画面サイズを比較して，正しいサイズにwidthとhightを変更する関数用意
	//
	if (!ft_cam_prepare(minirt->firstcam, minirt->width, minirt->hight))
		return (0);//camera構造体をいい感じにfreeしてやる必要がある．
// 	else if (!ft_obj_prepare(minirt->firstgob))
// 		return (0);
//	obj_prepareは不要説あり
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
		*firstcam = ft_make_screan_base(*firstcam);
		firstcam->cnum = i;
		firstcam->distance = (double *)malloc(sizeof(double) * width * hight);
		if (firstcam->distance == NULL)
			return (0);
		firstcam->image = (double *)malloc(sizeof(double) * width * hight);
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