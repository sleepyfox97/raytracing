// RGBはintだけど，必要に応じてdoubleキャストして，扱うと良い．
// RGBそれぞれに関して，ビット演算して，変換する関数を作る．

#include "./ft_test.h"


int	ft_get_rgb(int color, char c)
{
	int tmp;

	tmp = 255;
	if (c == 'r')
	{
		tmp = tmp << 16;
		tmp = (color & tmp) >> 16;
		return (tmp);
	}
	else if(c == 'g')
	{
		tmp = tmp << 8;
		tmp = (color & tmp) >> 8;
		return (tmp);
	}
	else if(c == 'b')
	{
		tmp = (color & tmp);
		return (tmp);
	}
	return (0);
}



int main()
{
	int r = 0;
	int g = 1;
	int b = 2;

	int color = (r << 16) |  (g << 8) | b;
	printf("color = %X\n", color);
	r = 0;
	g = 0;
	b = 0;
	r = ft_get_rgb(color, 'r');
	g = ft_get_rgb(color, 'g');
	b = ft_get_rgb(color, 'b');
	printf("r = %d  g = %d  b = %d\n", r, g, b);
	return (0);
}

// int	ft_r_change(int color, double tmp)
// {
// 	int	rtmp;
// 	int r;

// 	printf("%X\n", color);
// 	rtmp = 255 << 16;
// 	r = (rtmp & color) >> 16;
// 	r = r * tmp;
// 	color = color 
	
// }
