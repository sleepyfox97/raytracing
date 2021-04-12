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

typedef struct  s_vec3
{
    double x;
    double y;
    double z;
}               t_vec3;

typedef struct  s_cam
{
    t_vec3 p_cam;
    t_vec3 r_cam;
    t_vec3 s_b1;
    t_vec3 s_b2;
    double fov;
}               t_cam;

//p_cam:place of the camera;
//r_cam:ray of the camera;

//vector utility functions
t_vec3 ft_linear_transform(t_vec3 v1, t_vec3 v2, double a, double b);
double ft_inner_product(t_vec3 v1, t_vec3 v2);
t_vec3 ft_cross_product(t_vec3 v1, t_vec3 v2);
t_vec3 ft_make_nomalvec(t_vec3 v);
double ft_v_d_len(t_vec3 v);


t_cam ft_screan_base(t_cam cam, double width);



#endif