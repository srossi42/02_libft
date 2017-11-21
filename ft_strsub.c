#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t j;
	char *s_cpy;

	i = (size_t) start;
	j = 0;
	if (!(s_cpy = (char *)malloc(sizeof(*s_cpy) * (len + 1))))
		return (NULL);
	while (s[i] != '\0' && i < (len + start))
	{	
		s_cpy[j] = s[i];
		i++;
		j++;
	}
	s_cpy[j] = '\0';
	return (s_cpy);
}
