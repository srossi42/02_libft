#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	char *s_cpy;

	s_cpy = (char *)s;
 	i = 0;
	while(s_cpy[i] != c && s_cpy[i] != '\0')
		i++;
	if(s_cpy[i] != c)
		return (NULL);
	return (&s_cpy[i]);
}
