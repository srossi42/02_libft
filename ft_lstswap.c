#include <string.h>
#include "libft.h"

void	ft_lstswap(t_list **list, int	elem1_pos, int	elem2_pos)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int 	i;
	int		j;

	if (!elem1_pos || !elem2_pos || (elem1_pos == elem2_pos) || elem1_pos < 0 || elem2_pos < 0 || !*alist)
		return ;
	if (elem1_pos > elem2_pos)
	{
		i = elemp1_pos;
		elem1_pos = elem2_pos;
		elem2_pos = i;
	}
	i = 0;
	while (i < (elem1_pos - 1))
	{
		*alist = (*alist)->next;
		i++;
	}
	
	return ;


}
