#include "libft.h"
#include <string.h>

int	ft_lstelempos(t_list *list, t_list *elem)
{
	int i;
	t_list	*tmp;

	i = 0;
	if (list && elem)
	{
		tmp = list;
		while(tmp->next != NULL)
		{
			if (tmp == elem)
				return (i);
			i++;
			tmp = tmp->next;
		}
		if (tmp == elem)
			return (i);
	}
	return (-1);
}
