#include <stdlib.h>
#include <string.h>
#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(str = (char *)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);	
}
