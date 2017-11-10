#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	
	size_t i;
	char *str;
	char *src_cpy;

	i = 0;
	str = (char *)dst;
	src_cpy = (char *)src;
	while (i < n)
	{
		str[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
