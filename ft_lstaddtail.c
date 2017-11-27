#include <string.h>
#include "libft.h"

void ft_lstaddtail(t_list **elem, t_list *new_elem)
{
	t_list *tmp;

	tmp = *elem;
	if(new_elem && elem)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_elem;
		new_elem->next = NULL;
	}
}
