//計算前の準備として，各種ベクトルの計算とかをそれぞれに関してやる．

int	ft_prepare_print(t_minirt *minirt)
{
	int i;

	i = 0;
	if (!ft_cam_prepare(minirt->firstcam, minirt->width, minirt->hight))
		return (0);
	else if (!ft_obj_prepare(minirt->fistgob))
		return (0);
}

int	ft_cam_prepare(t_cam *firstcam, double width, double height)

int	ft_obj_prepare(t_gob *firstgob)
{

}


//ft_cam_prepare
//1:スクリーンベクトルを各カメラに関git して生成．
//2:双方向リストにする．
//3:distanceとimageをwidth,hightでmalloc