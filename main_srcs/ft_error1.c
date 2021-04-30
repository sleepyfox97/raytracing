#include "./miniRT.h"

//力の各関数においてerrorナンバー見て，ここでミスってるよって書き出す感じのコード作る．

void	ft_put_rtfile_error(char **line, int i)
{
		printf("\x1b[41m  \x1b[37m===Error===\x1b[39m  \x1b[49m\n");
		printf("type       : \x1b[33m.rt file error\033[m\n");
	if (i == 0)
		printf("\x1b[32myour .rt file is empty. check the file again\033[m\n");
	else
	{
		printf("error line : ");
		printf("\"\x1b[36m%s\x1b[39m\"\n", line[i]);
		printf("<you should check>\n");
		printf("0 : check every elemnts really in this line?\n");
		printf("1 : check wrong number input like \"0..0\" or \"10,,10\"\n");
		printf("2 : check the normarize vector is really normarized?\n");
	}
}