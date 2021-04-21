#include "./ft_test.h"
//まだ，本当の意味でのテストはできてない．
//最初の色をひょうじするところで無条件にambient lightにしてしまうのがよいかも？
int	ft_ambient_light(t_sp sp, t_al al, int  color)
{
	int r;
	int g;
	int b;
	int rcolor;

	r = ft_dr_r(sp.color, al.color, al.r);
	g = ft_dr_r(sp.color, al.color, al.r);
	b = ft_dr_r(sp.color, al.color, al.r);
	r = ft_max(r, ft_get_rgb(color, 'r'));
	g = ft_max(g, ft_get_rgb(color, 'g'));
	b = ft_max(b, ft_get_rgb(color, 'b'));
	rcolor = (r << 16) | (g << 8) | b;
	return (rcolor);
}


// int	ft_mirror_light(t_cam cam, t_light light, double t, int color, t_vec v)
// {

// }



//色の関数周りをいい感じに書き替えないと，このままでは，うまく行かない．
//とりあえず，光の実装はできた．
//設計を一から，考えて，そろそろ作ったほうがよさそう．
