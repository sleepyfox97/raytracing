#include "./miniRT.h"


void	print_struct_gob(t_gob *firstgob)
{
	int i = 1;
	while(firstgob != NULL)
	{
		printf("=======This is %d object=======\n", i);
		printf("type = %d\n", firstgob->type);
		if (firstgob->type == 1)
		{
			printf("this is sphere\n\n");
			printf("place of center\n");
			ft_put_vector(firstgob->p1);
			printf("\ndiameter = %lf\n", firstgob->d);
			printf("color = %X\n", firstgob->color);
		}
		firstgob = firstgob->next;
		i++;
	}
}

int main()
{
	char *line1 = "sp     0.0,0.0,20.6         12.6   255,0,255";
	char *line2 = "sp     0.1,0.1,0.24         99.9   31,31,31";
	t_minirt minirt;
	int i = 0;

	minirt.firstgob = NULL;
	i = ft_object_input(&minirt, line1);
	printf("i=%d\n", i);
	i = ft_object_input(&minirt, line2);
	printf("i=%d\n", i);
	print_struct_gob(minirt.firstgob);
}
