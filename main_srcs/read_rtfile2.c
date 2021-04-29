#include "./miniRT.h"

int	get_pv(char *line, int i, t_vec3 *v)
{
	double	x;
	double	y;
	double	z;

	i = ft_atof(line, i, &x);
	if (i == 0 || line[i++] != ',')
		return (0);
	i = ft_atof(line, i, &y);
	if (i == 0 || line[i++] != ',')
		return (0);
	i = ft_atof(line, i, &z);
	if (i == 0)
		return (0);
	v->x = x;
	v->y = y;
	v->z = z;
	return (i);
}

//t_vec3が二つ連続で並んでないといけない場合に使える，関数(cam, cy,tr,sq,pl)
int	get_two_vec(char *line, int i, t_vec3 *v1, t_vec3 *v2)
{
	if (!ft_isspace(line[i]))
		return (0);
	i = get_pv(line, i, v1);
	if (i == 0 || !ft_isspace(line[i]))
		return (0);
	i = get_pv(line, i, v2);
	if (i == 0 || !ft_isspace(line[i]))
		return (0);
	return (i);
}

int	get_three_vec(char *line, int i, t_vec3 *v1, t_vec3 *v2, t_vec3 *v3)
{
	if (!ft_isspace(line[i]))
		return (0);
	i = get_pv(line, i, v1);
	if (i == 0 || !ft_isspace(line[i]))
		return (0);
	i = get_pv(line, i, v2);
	if (i == 0 || !ft_isspace(line[i]))
		return (0);
	i = get_pv(line, i, v3);
	if (i == 0 || !ft_isspace(line[i]))
		return (0);
	return (i);
}

int	get_fov(char *line, int i, double *fov)
{
	if (!ft_isspace(line[i]))
		return (0);
	i = ft_atof(line, i, fov);
	if (line[i] != '\0' || (0 > *fov || *fov > 180))
		return (0);
	return (i);
}

int	ft_get_color(char *line, int i, int *color)
{
	double	r;
	double	g;
	double	b;

	i = ft_atol(line, i, &r);
	if (i == 0 || (r < 0 && 255 < r) || line[i++] != ',')
		return (0);
	i = ft_atol(line, i, &g);
	if (i == 0 || (g < 0 && 255 < g) || line[i++] != ',')
		return (0);
	i = ft_atol(line, i, &b);
	if (i == 0 || (b < 0 && 255 < b))
		return (0);
	*color = ((int)r << 16) | ((int)g << 8) | (int)b;
	return (i);
}
