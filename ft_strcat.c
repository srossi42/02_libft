#include "libft.h"

char *ft_strcat(char *restrict s1, const char *restrict s2)
{
	int i;
	int j;
	
	i = 0;
	j = 0;

	while (s1[j])
		j++;
	while (s2[i])
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
	return (s1);
}
