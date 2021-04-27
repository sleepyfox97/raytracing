#include "./miniRT.h"

int	ft_get_info(t_minirt *minirt, char *argv)
{
	char	*line;
	char	**sp_line;
	int 	fd;

	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		return (0);
	line = ft_read_rtfile(fd);
	sp_line = ft_split(line, '\n');
	if (sp_line == NULL)
	{
		free(line);
		return (0);
	}
	ft_input_info(&minirt, sp_line);
	return (1);
}

char	*ft_read_rtfile(int fd)
{
	char	*str;
	char	*line;
	ssize_t	buf;

	str = (char *)malloc(sizeof(char) * 1000);
	line = NULL;
	buf = 1;
	while(buf != 0)
	{
		buf = read(fd, str, 999);
		str[buf] = '\0';
		line = ft_strjoin(line, str);
		if (line == NULL)
		{
			free(str);
			return (NULL);
		}
	}
	free(str);
	return (line);
}

int	ft_input_info(t_minirt *minirt, char **line)
{
	int	i;
	int	j;

	i = 0;
	while(line[i] != NULL)
	{
		j = 0;
		if (line[i][0] == 'c')
			j = ft_cam_input(minirt->firstcam, line[i]);
		else if (line[i][0] == 'l')
			j = ft_light_input(minirt->firstlight, line[i]);
		else if (line[i][0] == 'A')
			j = ft_amblight_input(minirt->al, line[i]);
		else if (line[i][0] == 'R')
			j = ft_windowinfo_input(minirt, line[i]);
		else
		{
			j = ft_isobject(line[i]);
			if (j > 0)
				j = ft_object_input(minirt->firstgob, j);
		}
		if (j = 0)
		{
			//ft_free_list(minirt); ちゃんと作るの大変そう
			ft_free_array(line);
			return (0);
		}
		i++;
	}
	ft_free_array(line);
	return (1);
}

// int	ft_isobject(char *line)
// {
// 	if (ft_strlen(line) <= 2)
// 		return (0);
// 	if (line[0] == 's' && line[1] == 'p')
// 		return (1);
// 	else if (line[0] == 'p' && line[1] == 'l')
// 		return (2);
// 	else if (line[0] == 's' && line[1] == 'q')
// 		return (3);
// 	else if (line[0] == 'c' && line[1] == 'y')
// 		return (4);
// 	else if (line[0] == 't' && line[1] == 'r')
// 		return (5);
// 	else
// 		return (0);
// }




// int main(int argc, char *argv[])
// {
// 	t_minirt minirt;
// 	if(argc != 2)
// 		return (0);
// 	int i = 0;
// 	i = ft_get_info(&minirt, argv[1]);
// 	if (i != 0)
// 	{
// 		i = 0;
// 		while(minirt.test[i] != NULL)
// 		{
// 			printf("%s\n", minirt.test[i]);
// 			i++;
// 		}
// 	}
// 	return (0);
// }