#include "./test.h"

t_cam ft_screan_base(t_cam cam, double width)
{
    t_vec3 v_cs;
    t_vec3 v_b;

    v_cs = ft_linear_transform(cam.p_cam, cam.r_cam, 1, (width / (2 * tan(cam.fov / 2))));
    printf("%lf  %lf  %lf\n", v_cs.x, v_cs.y , v_cs.z);
    v_b.x = 1;
    v_b.y = 0;
    v_b.z = 0;
    if (cam.r_cam.y != 0)
        v_b.y = (-1) * (cam.r_cam.x) / cam.r_cam.y;  //if cam.r_cam.y == 0だったらバグる　二次方程式を解くようにする．
    v_b = ft_make_nomalvec(v_b);
    cam.s_b1 = v_b;
    v_b.x = 0;
    v_b.y = 1;
    v_b.z = 0;
    if (cam.r_cam.z != 0)
        v_b.z = (-1) * (cam.r_cam.y) / cam.r_cam.z; //if com.r_cam.z == 0だったらバグる-> 二次法的式をおとなしく解くようにする．
    v_b = ft_make_nomalvec(v_b);
    cam.s_b2 = v_b;
    return (cam);
}

//x軸上の点から原点方向に向かってみたとき,y軸上の転から原点方向に向かってみたときのスクリーンの基底ベクトルがおかしくなる．
//ｚ軸上の点から原点方向に向かってみたときの基底ベクトルは正しい．

int main() 
{
    t_cam cam;

    cam.p_cam.x = 0;
    cam.p_cam.y = 0;
    cam.p_cam.z = 0;
    cam.r_cam.x = 1;
    cam.r_cam.y = 1;
    cam.r_cam.z = 0;
    cam.r_cam = ft_make_nomalvec(cam.r_cam);
    cam.fov = M_PI / 4;
    cam = ft_screan_base(cam, 100);
    printf("cam.s_b1.x=%lf\n  cam.s_b1.y=%lf\n  cam.s_b1.z=%lf\n", cam.s_b1.x, cam.s_b1.y, cam.s_b1.z);
    printf("cam.s_b2.x=%lf\n  cam.s_b2.y=%lf\n  cam.s_b2.z=%lf\n", cam.s_b2.x, cam.s_b2.y, cam.s_b2.z);
    return (0);
}

//v_cs:screan center cordinate


// t_vec3 ft_make_rayvec(int x, int y, t_vec3 v_b)
// {

// }
