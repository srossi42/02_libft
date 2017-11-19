#include <stdlib.h>
#include <string.h>
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *str;
	int k;
	unsigned int i;

	k = 0;
	i = 0;
	while (s[k] != '\0')
		k++;
	if (!(str = (char *)malloc(sizeof(*str) * (k + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);	
}
