#include "./test.h"

//例外と普通の入力の対応
t_cam	ft_screan_base(t_cam cam)
{
	if (cam.r_cam.y == 0 && cam.r_cam.z == 0)
	{
		cam.s_b1 = ft_set_vecele(cam.s_b1, 0, 1, 0);
		cam.s_b2 = ft_set_vecele(cam.s_b1, 0, 0, 1);
	}
	else
		cam = ft_screan_base_normal(cam);
	return (cam);
}

//基本的なscreanの基底ベクトルの作成
t_cam	ft_screan_base_normal(t_cam cam)
{
	t_vec3	v_b;

	if (cam.r_cam.y == 0)
		v_b = ft_set_vecele(v_b, 0, 1, 0);
	else
		v_b = ft_set_vecele(v_b, 1, ((-1) * (cam.r_cam.x) / cam.r_cam.y), 0);
	cam.s_b1 = ft_make_nomalvec(v_b);
	if (cam.r_cam.z == 0)
		v_b = ft_set_vecele(v_b, 0, 0, 1);
	else if (cam.r_cam.y != 0)
		v_b = ft_set_vecele(v_b, 0, 1, ((-1) * (cam.r_cam.y) / cam.r_cam.z));
	else if (cam.r_cam.y == 0)
		v_b = ft_set_vecele(v_b, 1, 0, ((-1) * (cam.r_cam.x) / cam.r_cam.z));
	cam.s_b2 = ft_make_nomalvec(v_b);
	return (cam);
}

//上で作ったbaseをもとに，rayを作る．
t_vec3	ft_make_ray(t_cam cam, int x, int y, double width)
{
	t_vec3	v_ray;
	t_vec3	v_cs;

	v_cs = ft_linear_transform(cam.p_cam, cam.r_cam, 1, (width / (2 * tan(cam.fov / 2))));
	v_ray = ft_linear_transform(cam.s_b1, cam.s_b2, x, y); //ここミスってる！！！！！
	v_ray = ft_linear_transform(v_ray, v_cs, 1, 1);
	return (v_ray);
}
	//screanの二つのベクトルの正当性を確認する．

	//cam.r_cam.y == 0の時は，y軸方向にscrean平面のベクトルが一本立ってないとおかしい．
	//printf("%lf  %lf  %lf\n", v_cs.x, v_cs.y , v_cs.z);
	// v_b.x = 1;
	// v_b.z = 0;
	// v_b.y = (-1) * (cam.r_cam.x) / cam.r_cam.y;  
	//if cam.r_cam.y == 0だったらバグる　二次方程式を解くようにする．
	// v_b.x = 0;
	// v_b.y = 1;
	// if (cam.r_cam.z != 0)
	// v_b.z = (-1) * (cam.r_cam.y) / cam.r_cam.z; if com.r_cam.z == 0だったらバグる
	//       -> 二次法的式をおとなしく解くようにする．
	// v_b = ft_make_nomalvec(v_b);
	//x軸上の点から原点方向に向かってみたとき,
	//   ->y軸上の転から原点方向に向かってみたときのスクリーンの基底ベクトルがおかしくなる．
	//ｚ軸上の点から原点方向に向かってみたときの基底ベクトルは正しい．
	//　screan平面の中心座標を出してくれる．
	// 	t_vec3	v_cs;
	//
	//v_cs:screan center cordinate
	// t_vec3 ft_make_rayvec(int x, int y, t_vec3 v_b)
	// {
	// }

// int	main() 
// {
// 	t_cam	cam;

// 	cam.p_cam.x = 0;
// 	cam.p_cam.y = 0;
// 	cam.p_cam.z = 0;
// 	cam.r_cam.x = 0;
// 	cam.r_cam.y = 0;
// 	cam.r_cam.z = 1;
// 	cam.r_cam = ft_make_nomalvec(cam.r_cam);
// 	cam.fov = M_PI / 4;
// 	cam = ft_screan_base(cam);
// 	printf("cam.s_b1.x=%lf\n  cam.s_b1.y=%lf\n  cam.s_b1.z=%lf\n", cam.s_b1.x, cam.s_b1.y, cam.s_b1.z);
// 	printf("cam.s_b2.x=%lf\n  cam.s_b2.y=%lf\n  cam.s_b2.z=%lf\n", cam.s_b2.x, cam.s_b2.y, cam.s_b2.z);
// 	return (0);
// }
