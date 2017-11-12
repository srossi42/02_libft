#include <stdio.h>
#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr_s;
	size_t i;

	ptr_s = (unsigned char *)s;
	i = 0;
	while (ptr_s[i] != (unsigned char)c && i < n)
		i++;
	if (i < n)
		return (ptr_s = &ptr_s[i]);
	else
		return (NULL);
}
