#include "libft.h"

char *ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t j;
	
	i = 0;	
	j = 0;
	while (s1[j])
		j++;
	while (n && s2[i])
	{
		s1[j] = s2[i];
		i++;
		j++;
		n--;
	}	
	s1[j] = '\0';
	return (s1);
}
