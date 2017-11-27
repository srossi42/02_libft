#include "libft.h"

int	ft_lstlen(t_list **alst)
{
	int i;

	i = 0;
	while (*alst)
	{
		(*alst) = (*alst)->next;
		i++;
	}
	return (i);
}
