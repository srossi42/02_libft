#include <string.h>
#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int mem;
	char *t1;
	char *t2;

	i = 0;
	j = 0;
	t1 = (char *)s1;
	t2 = (char *)s2;
	if (t2[0] == '\0')
		return (t1);
	while (t1)
	{
		if (i != 0)
			i = mem + 1;
	 	while (t1[i] != t2[j])
			i++; 
		if (t1[i] == '\0')
			return (NULL);
		mem = i;
		while (t1[i] == t2[j])
		{
			i++;
			j++;
		}
		if (t2[j] != '\0')
			j = 0;
		else 
			return (&t1[mem]);
	}
	return (NULL);
}
