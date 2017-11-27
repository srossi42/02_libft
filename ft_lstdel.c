#include <stdlib.h>
#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	
	if (!(*alst) || !(*del))
		return ;
	while (*alst)
	{
		ptr = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = ptr;
	}
	(*alst) = NULL;
}
