#include <string.h>
#include "libft.h"

void	ft_lstmodify_cont(t_list *list, int elem_pos, void *content)
{
	int i;
	int imax;

	imax = ft_lstlen(&list);
	i = 0;
	if ((list != NULL) && elem_pos >= 0 && content != NULL && elem_pos < imax)
	{
		while (i < elem_pos)
		{
			list = list->next;
			i++;
		}
		list->content = content;
	}
}
