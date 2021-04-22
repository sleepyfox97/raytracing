#include "./miniRT.h"

//input infoの中で読みながらcheckするが楽そうだけど．．．
//ｃとRとAが一つもない場合には，ファイルerrorにする．
int	ft_get_info(t_minirt minirt, char *argv)
{
	char	*line;
	int 	fd;

	while(get_next_line(&line, fd) > 0)
	{
		if (ft_input_info(minirt, line) > 0)
		{
			//fr_free(minirt);
			//
		}
	}
}

int ft_input_info(t_minirt minirt, char *line)
{

}




