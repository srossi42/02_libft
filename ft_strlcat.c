#include "libft.h"

size_t ft_strlcat(char * restrict dst, const char * restrict src, size_t size)
{
	size_t i;
	size_t j;
	size_t n;
	size_t s_ln;
	size_t d_ln;
	
	i = 0;	
	j = 0;
	s_ln = 0;
	while (dst[i] && i < size)
		i++;
	d_ln = i;
	while (src[s_ln])
		s_ln++;
	if (size <= i || (size > d_ln && size > s_ln && size < (d_ln + s_ln)))
		return (size + s_ln);
	else 
	{
		n = size - i - 1;
		while (n--)
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (d_ln + s_ln);
	}
}