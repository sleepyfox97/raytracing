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
	if (i == 0)
		return (0);
	if (!ft_isspace(line[i]))
		return (0);
	i = get_pv(line, i, v2);
	if (i == 0)
		return (0);
	if (!ft_isspace(line[i]))
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
//循環リストは，最初は双方向リストとして扱い，最後にくっつけることで実現する．

int	ft_cam_imput(t_cam **firstcam, char *line)
{
	int		i;
	t_cam	*new;

	new = (t_cam *)malloc(sizeof(t_cam));
	if (!new)
		return (0);
	i = 1;
	i = get_two_vec(line, i, &(new->p), &(new->vd));
	if (i == 0)
		return (ft_safe_free1(new));
	i = get_fov(line, i, &(new->fov));
	if (i == 0)
		return (ft_safe_free1(new));
	if (*firstcam == NULL)
	{
		*firstcam = new;
		new->prev = NULL;
	}
	else
	{
		new->prev = ft_camlstlast(*firstcam);
		ft_camlstlast(*firstcam)->next = new;
	}
	new->next = NULL;
	return (1);
}

int	ft_windowinfo_input(t_minirt *minirt, char *line)
{
	int	i;

	i = 1;
	i = ft_atol(line, i, &(minirt->width));
	if (i == 0)
		return (0);
	i = ft_atol(line, i, &(minirt->hight));
	if (i == 0)
		return (0);
	if (line[i] != '\0')
		return (0);
	return (i);
}

// int main()
// {
// 	char *line = "R   510 500";
// 	int i = 0;
// 	t_minirt minirt;

// 	i = ft_windowinfo_input(&minirt, line);
// 	printf("%d\n%lf. %lf\n", i, minirt.width, minirt.hight);
// }

// int main()
// {
// 	char *line = "c   -50.0,0,20  0,..0,1 70  ";
// 	int i = 0;
// 	t_cam	*cam;
// 	t_vec3 a;

// 	// cam = (t_cam *)malloc(sizeof(t_cam));
// 	// i = get_two_vec(line, 2, &(cam->p), &(cam->vd));
// 	cam = NULL;
// 	i = ft_cam_imput(&cam, line);
// 	printf("i = %d\n", i);
// 	system("leaks a.out");
	// ft_put_vector(cam->p);
	// ft_put_vector(cam->vd);
	// printf("fov = %lf", cam->fov);
//}
// えらーケースの場合は，構造体自体がつながれずに終わってるので，注意
