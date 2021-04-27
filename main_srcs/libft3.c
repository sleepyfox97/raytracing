#include "./miniRT.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned const char *)src;
	if (dst || src)
	{
		while (n-- > 0)
			*s1++ = *s2++;
		return (dst);
	}
	return (NULL);
}