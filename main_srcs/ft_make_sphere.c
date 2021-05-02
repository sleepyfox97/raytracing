// #include "./miniRT.h"

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

