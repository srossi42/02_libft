#include <unistd.h>
#include "libft.h"

void ft_putendl(char const *s)
{
	int i;
	char c;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{	
		c = (char)s[i];
		write(1, &c, 1);
		i++;	
	}
	c = '\n';
	write(1, &c, 1);
}
