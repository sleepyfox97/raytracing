#include "miniRT.h"

int main(int argc, char *argv[])
{
	t_minirt	minirt;

	if (argc != 2 && argc != 3)
	{
		printf("argument error. Arguments have to be 2 or 3.\n");
		return (0);
	}
	else if(argc == 2)
	{
		ft_type2(minirt, argv[1]);
	}
	else if (argc == 3)
	{
		printf("I didn't make argc == 3 program\n");
	}
	reutrn (0);
}


//1:read rtfile.
//2:do rendering.
//3:free elements.
ft_type2(t_minirt minirt, char argv[1]);
{
	ft_get_info(minirt, argv[1]);
	//ft_show_image(minirt.light, minirt.cam, minirt.am, minirt.gob);
	//free everything.
}