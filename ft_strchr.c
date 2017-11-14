#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	char *s_cpy;

	s_cpy = (char *)s;
 	i = 0;
	while(s_cpy[i] != c)
		i++;
	return (&s_cpy[i]);
}
