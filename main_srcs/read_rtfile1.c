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
		return (ft_safe_free1(sp_line));
	if (!ft_input_info(&minirt, sp_line))
		return (0);
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
			j = ft_cam_input(&(minirt->firstcam), line[i]);
		else if (line[i][0] == 'l')
			j = ft_light_input(&(minirt->firstlight), line[i]);
		else if (line[i][0] == 'A')
			j = ft_amblight_input(&(minirt->al), line[i]);
		else if (line[i][0] == 'R')
			j = ft_windowinfo_input(minirt, line[i]);
		else
			j = ft_object_input(minirt, line);
		//RやAが二回来た場合，Cが一回も無かった場合などに対するerror処理がまだ．
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




