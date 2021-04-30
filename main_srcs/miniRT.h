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
	struct s_cam	*prev;
	struct s_cam	*next;
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
	struct s_light	*next;
}	t_light;


//flag initialize -1 first
typedef struct s_amblight
{
	double	r;
	int		color;
	int		flag;
}	t_amblight;

//gob means geometric object.
//vno: normalized orientation vector.
//vctoc:vector from camera to object center. you have to chage if camera change.
//dは直径なので注意(rtファイルで与えられるのは直径)
//use h onluy for cylinder hight.
typedef struct s_gob
{
	int		type;
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
	t_vec3	vno;
	double	d;
	double	h;
	int		color;
	t_vec3	vctoc;
	struct s_gob	*prev;
	struct s_gob	*next;
}	t_gob;

//perror is in stdio.h, strerror is in string.h
//from this struct, we can reach every element used in this program.
typedef struct s_minirt
{
	t_cam		*firstcam;
	t_light		*firstlight;
	t_gob		*firstgob;
	t_amblight	al;
	double		width;
	double		hight;
}	t_minirt;

//in main file
//initialize minirt struct;
void	ft_initialize_minirt(t_minirt *minirt);
//if argc == 2, do this function.
void	ft_type2(t_minirt minirt, char *argv);


//read RTfile.
//in read RTfile1　読み取りができるとこまでした，read RTfile2以降の関数との組み合わせはまだ．
int		ft_get_info(t_minirt *minirt, char *argv);
char	*ft_read_rtfile(int fd);
int		ft_input_info(t_minirt *minirt, char **line);
int		ft_switch_inputtype(t_minirt *minirt, char *line);

//in read RTfile2(util functions to get each information)
int		get_pv(char *line, int i, t_vec3 *v);
int		get_two_vec(char *line, int i, t_vec3 *v1, t_vec3 *v2);
int		get_three_vec(char *line, int i, t_vec3 *v1, t_vec3 *v2, t_vec3 *v3);
int		get_fov(char *line, int i, double *fov);
int		ft_get_color(char *line, int i, int *color);
//in read RTfile3(for camera, window, light)
int		ft_cam_input(t_cam **firstcam, char *line);
int		ft_windowinfo_input(t_minirt *minirt, char *line);
int		ft_light_input(t_light **firstlight, char *line);
int		ft_amblight_input(t_amblight *al, char *line);
//in read RTfile4(object input main, sphere and plane)
int		ft_object_input(t_minirt *minirt, char *line);
int		ft_isobject(char *line);
int		ft_sphere_input(t_gob **firstgob, char *line);
int		ft_plane_input(t_gob **firstgob, char *line);
//in read RTfile5(square, cylinder and triangle)
int		ft_square_input(t_gob **firstgob, char *line);
int		ft_cylinder_input(t_gob **firstgob, char *line);
int		ft_input_SqAndCy_sub(t_gob *new, char *line, int i);
int		ft_triangle_input(t_gob **firstgob, char *line);

//function in libft1
int		ft_isspace(char c);
int		ft_atol(char *s, int i, double *result);
int		ft_atof(char *s, int i, double *result);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
//function in libft2
void	ft_free_array(char **s);
char	**ft_split(char const *s, char c);
//function in libft3
void	*ft_memcpy(void *dst, const void *src, size_t n);
t_cam	*ft_camlstlast(t_cam *lst);
t_light	*ft_lightlstlast(t_light *lst);
t_gob	*ft_oblstlast(t_gob *lst);
int	ft_safe_free1(void *ptr);
//function in libft4
void	ft_clear_minirt(t_minirt *minirt);
void	ft_camlstclear(t_cam *firstcam);
void	ft_lightlstclear(t_light *firstlight);
void	ft_oblstclear(t_gob *firstgob);

//vector util1
t_vec3	ft_linear_transform(t_vec3 v1, t_vec3 v2, double a, double b);
double	ft_inner_product(t_vec3 v1, t_vec3 v2);
t_vec3	ft_cross_product(t_vec3 v1, t_vec3 v2);
double	ft_v_d_len(t_vec3 v);
t_vec3	ft_make_unitvec(t_vec3 v);
//vector util2
t_vec3	ft_set_vecele(double x, double y, double z);
void	ft_put_vector(t_vec3 v);
t_vec3	ft_gramschmidt_1(t_vec3 v1, t_vec3 v2);
t_vec3	ft_gramschmidt_2(t_vec3 v1, t_vec3 v2, t_vec3 v3);

//error stdout
void	ft_put_rtfile_error(char **line, int i);

//for test
void	print_minirt_struct(t_minirt *minirt);
void	print_window_al(t_minirt *minirt);
void	print_struct_light(t_light *fisrt);
void	print_struct_cam(t_cam *fisrt);
void	print_struct_gob(t_gob *firstgob);
#endif
