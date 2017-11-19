#include <stdlib.h>
#include <string.h>
#include "libft.h"

char *ft_strnew(size_t size)
{
	char *str;
	size_t i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * size)) && size != 0)
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);

}
