#include "./ft_test.h"

t_cam	ft_make_screan_base(t_cam cam)
{
	if (cam.r_cam.x == 0 && cam.r_cam.y >= 0)
		cam.s_b1 = ft_set_vecele(1, 0, 0);
	else if (cam.r_cam.x == 0 && cam.r_cam.y < 0)
		cam.s_b1 = ft_set_vecele(-1, 0, 0);
	else if (cam.r_cam.y == 0 && cam.r_cam.x > 0)
		cam.s_b1 = ft_set_vecele(0, -1, 0);
	else if (cam.r_cam.y == 0 && cam.r_cam.x < 0)
		cam.s_b1 = ft_set_vecele(0, 1, 0);
	else
	{
		cam.s_b1.x = 1;
		cam.s_b1.y = (-1) * (cam.r_cam.x * cam.s_b1.x) / cam.r_cam.y;
	}
	if (cam.r_cam.z == 0)
		cam.s_b2 = ft_set_vecele(0, 0, 1);
	else
		cam.s_b2 = ft_cross_product(cam.s_b1, cam.r_cam);
	cam.s_b1 = ft_make_unitvec(cam.s_b1);
	cam.s_b2 = ft_make_unitvec(cam.s_b2);
	return (cam);
}

//to get p_to_sc vector, you only do following contents.
//t_vec3 p_to_sc;
//p_to_sc = ft_linear_transform(r_cam, r_cam,(width/(2*tan(FOV/2))), 0);
//

t_vec3	ft_make_ray(t_cam cam, double x, double y)
{
	t_vec3 ray_vec;
	t_vec3 tmp_vec;

	tmp_vec = ft_linear_transform(cam.s_b1, cam.s_b2, x, y);
	ray_vec = ft_linear_transform(tmp_vec, cam.p_to_sc, 1, 1);
	return (ray_vec);
}

// int	main()
// {
// 	t_cam	cam;
// 	t_vec3 v;

// 	cam.p_cam.x = 0;
// 	cam.p_cam.y = 0;
// 	cam.p_cam.z = 0;
// 	cam.r_cam.x = 0;
// 	cam.r_cam.y = ;
// 	cam.r_cam.z = 1;
// 	cam.r_cam = ft_make_unitvec(cam.r_cam);
// 	cam.fov = M_PI / 4;
// 	double width = 500;
// 	cam = ft_make_screan_base(cam);
// 	printf("cam.s_b1.x=%lf  cam.s_b1.y=%lf  cam.s_b1.z=%lf\n\n", cam.s_b1.x, cam.s_b1.y, cam.s_b1.z);
// 	printf("cam.s_b2.x=%lf  cam.s_b2.y=%lf  cam.s_b2.z=%lf\n\n", cam.s_b2.x, cam.s_b2.y, cam.s_b2.z);

// 	double b1_b2 = ft_inner_product(cam.s_b1, cam.s_b2);
// 	double b1_cam = ft_inner_product(cam.s_b1, cam.r_cam);
// 	double b2_cam = ft_inner_product(cam.s_b2, cam.r_cam);
// 	printf("b1_b2=%lf  b1_cam=%lf  b2_cam=%lf\n",b1_b2, b1_cam, b2_cam);

// 	cam.p_to_sc = ft_linear_transform(cam.r_cam, cam.r_cam, (width / (2 * tan(cam.fov / 2))), 0);
// 	v = ft_make_ray(cam, 0, 0);
// 	printf("v.x=%lf\nv.y=%lf\nv.z=%lf\n", v.x, v.y,v.z);
// 	return (0);
// }
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

	//camの方向ベクトルが，(1,1,z)のパターンの時にバグる．



//widthはウィンドウの幅なのか，横のピクセル数なのかで微妙に代わる．
//スクリーンが上下左右に1/2ピクセルずれたものになる気がする．
