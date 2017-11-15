#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int mem;
	char *s_cpy;

	s_cpy = (char *)s;
 	i = 0;
	mem = 0;
	while(s_cpy[i] != '\0')
	{
		if (s_cpy[i] == c)
			mem = i;
		i++;
	}
	if (mem > 0)
		return (&s_cpy[mem]);
	else if (c == '\0')
		return (&s_cpy[i]);
	else
		return (NULL);
}
