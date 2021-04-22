#include "./miniRT.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atof(char *s, double *result)
{
	double	i;

	i = 1;
	if (ft_atol(s, result) == 0)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		s++;
	while ('0' <= *s && *s <= '9')
		s++;
	if (*s == '.')
	{
		s++;
		while ('0' <= *(s) && *(s) <= '9')
			*result = *result + (*(s++) - '0') * (i *= 0.1);
	}
	return (1);
}

int	ft_atol(char *s, double *result)
{
	long	minus;

	minus = 1;
	*result = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			minus = -1;
	while ('0' <= *s && *s <= '9')
	{
		if (*result > LONG_MAX / 10 && minus == 1)
			return (0);
		else if (*result == LONG_MAX / 10 && *s > '7' && minus == 1)
			return (0);
		else if (*result > LONG_MAX / 10 && minus == -1)
			return (0);
		else if (*result == LONG_MAX / 10 && *s > '8' && minus == -1)
			return (0);
		*result = ((*s++) - '0') + (*result) * 10;
	}
	*result = (*result) * minus;
	return (1);
}

int	main(int argc, char *argv[])
{
	double	a;
	double	b;

	if (argc != 3)
		return (0);
	ft_atol(argv[1], &a);
	ft_atof(argv[2], &b);
	printf("a=%ld b=%.30lf\n", (long)a, b);
	return (0);
}
