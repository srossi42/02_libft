#include "libft.h"

void ft_lstaddafter(t_list **elem, t_list *new_elem)
{
	t_list *tmp;

	if (new_elem != NULL)
	{
		if (*elem == NULL)
			*elem = new_elem;
		else
		{
			if ((*elem)->next)
			{
				tmp = (*elem)->next;
				(*elem)->next = new_elem;
				new_elem->next = tmp;
			}
			else
				ft_lstaddtail(elem, new_elem);
		}
	}
}
