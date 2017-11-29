#include "libft.h"

int	ft_lstlen(t_list **alst)
{
	int 	i;
	t_list	*tmp;

	i = 0;
	tmp = *alst;
	if (*alst != NULL)
	{

		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
