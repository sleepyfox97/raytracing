#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdint.h>
# include <limits.h>

# include <X11/Xlib.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
//# include "./mlx_linux/mlx.h"

//3D vector
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

//カメラの回転のことを考えたら，最初から，クオータニオンで持ってた方が多分いいんだけど，
//今回は，必要になったら構造体要素に追加して，変換のプログラム書くことにする
//camera circular struct list.
//p:place, vd:direction vector, vsb:screen base vector,
//vptos:vector form camera place to screan origin,vray:ray vector from camera
//prev means before camera struct and next means next camera struct.
//image: this varinable has every pixel color informatin,
//so, use pixel put to this varinable, we can see the window view.
typedef struct s_cam
{
	t_vec3	p;
	t_vec3	vd;
	double	fov;
	t_vec3	vsb1;
	t_vec3	vsb2;
	t_vec3	vptos;
	t_vec3	vray;
	struct	t_cam	*prev;
	struct	t_cam	*next;
	int		*image;
}	t_cam;

//p:place of light, r:brightneess of light ratio
//vctol: vector from cam to light, you have to chang this for each camera
typedef struct s_light
{
	t_vec3	p;
	double	r;
	int		color;
	t_vec3	vctol;
	struct t_light	*prev;
	struct t_light	*next;
}	t_light;

typedef struct s_amblight
{
	double	r;
	int		color;
}	t_amblight;

//gob means geometric object.
//vno: normalized orientation vector.
//vctoc:vector from camera to object center. you have to chage if camera change.
//dは直径なので注意(rtファイルで与えられるのは直径)
//use h onluy for cylinder hight.
typedef struct s_gob
{
	char	type[3];
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
	t_vec3	vno;
	double	d;
	double	h;
	int		color;
	t_vec3	vctoc;
	struct t_gob	*prev;
	struct t_gob	*next;
}	t_gob;

//perror is in stdio.h, strerror is in string.h
//from this struct, we can reach every element used in this program.
typedef struct s_minirt
{
	t_cam		*firstcam;
	t_light		*firstlight;
	t_gob		*firstgob;
	t_amblight	*al;
	int			widht;
	int			hight;
}	t_minirt;

//read RTfile.
int	ft_get_info(t_minirt minirt, char *argv);


int	ft_isspace(char c);
int	ft_atof(char *s, double *result);
int	ft_atol(char *s, double *result);
#endif
