#include "./ft_test.h"

void	ft_set_vecele(t_vec3 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	return ;
}

void	ft_put_vector(t_vec3 v)
{
	printf("v.x=%lf, v.y=%lf, v.z~%lf\n",v.x, v.y, v.z);
	return ;
}
