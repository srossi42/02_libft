#include "libft.h"

char *ft_strncpy(char * dst, const char * src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && len)	
	{
		dst[i] = src[i];
		len --;
		i++;
	}
	if (len)
	{
		while (len)
		{
			dst[i] = '\0';
			len--;
			i++;
		}
	}
   return (dst);	
}	