#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;
	int mem;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			mem = i;
		i++;
	}
	return (&s[mem]);
}
