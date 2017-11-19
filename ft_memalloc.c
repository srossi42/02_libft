#include <stdlib.h> 
#include <string.h> 
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;
	size_t i;
	
	i = 0;
	if (!(ptr = (void *)malloc(size)) || !size)
		return (NULL);
	while (i < size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
