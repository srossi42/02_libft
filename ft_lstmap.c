#include <string.h>
#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*first_elem;

	tmp = f(lst);
	if (!(new = (t_list *)malloc(sizeof((tmp->content_size)))))
		return (NULL);
	new->content = tmp->content;
	new->next = NULL;
	first_elem = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
	//	if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
	//		return (NULL);
	//	new = new->next;
		if (!(new = (t_list *)malloc(sizeof((tmp->content_size)))))
			return (NULL);
		new->content = tmp->content;
		printf("test %s\n", new->content);
		new->next = NULL;
		ft_lstaddtail(&first_elem, new);
		printf("test %s\n", new->content);
		lst = lst->next;
	}
	return (first_elem);
}
