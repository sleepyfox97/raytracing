#include "./miniRT.h"

int main(int argc, char *argv[])
{
	t_minirt	minirt;
	int			i;

	i = 0;
	ft_initialize_minirt(&minirt);
	if (argc != 2 && argc != 3)
	{
		printf("Error\n\nargument error.\nArguments have to be 2 or 3.\n");
		return (0);
	}
	else if(argc == 2) //argv[1]が.rtで終わるファイルかを確認する．
	{
		ft_type2(minirt, argv[1]);
	}
	else if (argc == 3)
	{
		printf("I didn't make argc == 3 program\n");
	}
	return (0);
}


//1:read rtfile.
//2:do rendering.
//3:free elements.
void	ft_type2(t_minirt minirt, char *argv)
{
	int i;

	i = 0;
	i = ft_get_info(&minirt, argv);
	if (i == 0)
		return ;
	else if (i == 1)
		print_minirt_struct(&minirt);
	ft_show_image(minirt);
	//free everything.
	return ;
}

void	ft_initialize_minirt(t_minirt *minirt)
{
	minirt->firstcam = NULL;
	minirt->firstlight = NULL;
	minirt->firstgob = NULL;
	minirt->al.flag = -1;
	minirt->width = -1;
	minirt->hight = -1;
}
