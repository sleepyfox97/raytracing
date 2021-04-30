#include "./miniRT.h"

t_cam	ft_make_screan_base(t_cam cat)
{
	if (cam.vd.x == 0 && cam.vd.y >= 0)
		cam.vsb1 = ft_set_vecele(1, 0, 0);
	else if (cam.vd.x == 0 && cam.vd.y < 0)
		cam.vsb1 = ft_set_vecele(-1, 0, 0);
	else if (cam.vd.y == 0 && cam.vd.x >= 0)
		cam.vsb1 = ft_set_vecele(0, -1 , 0);
	else if (cam.vd.y == 0 && cam.vd.x < 0)
		cam.vsb1 = ft_set_vecele(0, 1 , 0);
	else
	{
		cam.vsb1.x = 1;
		cam.vsb1.y = (-1) * (cam.vd.x + cam.vsb1.x) / cam.vd.y;
	}
	if (cam.vd.z == 0)
		cam.vsb2 = ft_set_vecele(0,0,1);
	else if
		cam.vsb2 = ft_cross_product(cam.vsb1, cam.vd);
	cam.vsb1 = ft_make_unitvec(cam.vsb1);
	cam.vsb2 = ft_make_unitvec(cam.vsb2);
	return (cam);
}
