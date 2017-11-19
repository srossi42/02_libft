#include <string.h>
#include <stdlib.h>
#include "libft.h"

void ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
