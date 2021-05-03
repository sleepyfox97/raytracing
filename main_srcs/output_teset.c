#include "./miniRT.h"

void print_prepare_cam(t_cam *first)
{
	int i = 1;
	while(1)
	{
		printf("\n\x1b[35m========This is %d camera=========\033[m\n", i);
		printf("screan base vector 1 \n");
		ft_put_vector(first->vsb1);
		printf("\nscrean base vector 2\n");
		ft_put_vector(first->vsb2);
		printf("vctos\n");
		printf("fov = %lf", first->fov);
		printf("\nimage pointor\n");
		ft_put_vector(first->vptos);
		printf("*image =%p\n", first->image);
		printf("cam->next = %p\n", first->next);
		printf("cam       = %p\n", first);
		printf("cam->prev = %p\n", first->prev);
		first = first->next;
		if (first->cnum == 1)
			break ;
		i++;
	}
	return ;
}


void	print_prepare_obj(t_gob *first)
{
	int i;

	i = 0;
	while (1)
	{
		printf("\n\x1b[32m=======This is %d object=======\033[m\n", i);
		printf("type = %d\n", first->type);
		if (first->type == 1)
		{
			printf("this is sphere\n\n");
		printf("sp->next = %p\n", first->next);
		printf("sp       = %p\n", first);
		}
		if (first->next == NULL)
			break ;
		first = first->next;
		i++;
	}
}