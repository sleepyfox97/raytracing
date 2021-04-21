#ifndef TEST_H
# define TEST_H

# include <X11/Xlib.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx_linux/mlx.h"

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct	s_cam
{
	t_vec3	p_cam;
	t_vec3	r_cam;
	double	fov;
	t_vec3	s_b1;
	t_vec3	s_b2;
	t_vec3	p_to_sc;
	t_vec3	v_ray; // いる気がしたけど，いらないと思ったけどいる？
}	t_cam;

typedef struct	s_sp
{
	t_vec3	sp_c;
	int		color;
	double	r;
	t_vec3	cam_to_s;
}	t_sp;

typedef struct	s_light
{
	t_vec3	l_p;
	int		color;
	double	r;
	t_vec3	c_to_l;//いらなそう
}	t_light;

typedef struct s_al
{
	double	r;
	int		color;
}				t_al;

//p_cam:place of the camera;
//r_cam:ray of the camera;

//vector utility functions
t_vec3	ft_linear_transform(t_vec3 v1, t_vec3 v2, double a, double b);
double	ft_inner_product(t_vec3 v1, t_vec3 v2);
t_vec3	ft_cross_product(t_vec3 v1, t_vec3 v2);
t_vec3	ft_make_unitvec(t_vec3 v);
double	ft_v_d_len(t_vec3 v);
t_vec3	ft_set_vecele(double x, double y, double z);
t_vec3	ft_gramschmidt_1(t_vec3 v1, t_vec3 v2);
t_vec3	ft_gramschmidt_2(t_vec3 v1, t_vec3 v2, t_vec3 v3);


t_cam	ft_make_screan_base(t_cam cam);
t_vec3	ft_make_ray(t_cam cam, double  x, double y);

int		make_sphere(t_cam *cam, t_sp sp, double x, double y, double *t);

void	ft_put_vector(t_vec3 v);

int	ft_get_rgb(int color, char c);


int	ft_ambient_light(t_sp sp, t_al al, int  color);
int	ft_diffuse_reflection(t_cam cam, t_light light, const double t, int color, t_vec3 v);
int	ft_dr_r(int color, int lcolor, double cos);
int	ft_dr_g(int color, int lcolor, double cos);
int	ft_dr_b(int color, int lcolor, double cos);

double	ft_max(double a, double b);
double	ft_min(double a, double b);
#endif