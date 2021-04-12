#include "./test.h"

t_vec3  ft_linear_transform(t_vec3 v1, t_vec3 v2, double a, double b)
{
    t_vec3 v3;

    if (b == 0)
        {
            v3.x = a * v1.x;
            v3.y = a * v1.y;
            v3.z = a * v1.z;
            return (v3);
        }
    else
    {
        v3.x = a * v1.x + b * v2.x;
        v3.y = a * v1.y + b * v2.y;
        v3.z = a * v1.z + b * v2.z;
        return (v3); 
    }
}

double ft_inner_product(t_vec3 v1, t_vec3 v2)
{
    double re;

    re = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    return (re);
}

t_vec3 ft_cross_product(t_vec3 v1, t_vec3 v2)
{
    t_vec3 v3;

    v3.x = v1.y * v2.z - v1.z * v2.y;
    v3.y = v1.z * v2.x - v1.x * v2.z;
    v3.z = v1.x * v2.y - v1.y * v2.x;
    return (v3);
}

double ft_v_d_len(t_vec3 v)
{
    double vec_double_len;

    vec_double_len = v.x * v.x + v.y * v.y + v.z * v.z;
    return (vec_double_len);
}

t_vec3 ft_make_nomalvec(t_vec3 v)
{
    double v_len;

    v_len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    v.x = v.x / v_len;
    v.y = v.y / v_len;
    v.z = v.z / v_len;
    return (v); 
}



// int main()
// {
//     t_vec3 v1, v2, v3;
//     double i_p = 0;

//     v1.x = 1;
//     v1.y = 2;
//     v1.z = 3;

//     v2.x = 3;
//     v2.y = 4;
//     v2.z = 0;


//     v3 = ft_linear_transform(v1, v2, 2, 2);
//     printf("v3.x=%lf\nv3.y=%lf\nv3.z=%lf\n\n", v3.x, v3.y, v3.z);
//     v3 = ft_make_nomalvec(v2);
//     printf("v3.x=%lf\nv3.y=%lf\nv3.z=%lf\n\n", v3.x, v3.y, v3.z);
//     v3 = ft_cross_product(v1, v2);
//     printf("v3.x=%lf\nv3.y=%lf\nv3.z=%lf\n\n", v3.x, v3.y, v3.z);
//     i_p = ft_inner_product(v1, v2);
//     printf("i_p = %lf", i_p);
// }