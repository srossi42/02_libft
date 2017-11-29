#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tmp;
	t_list	*begin;
	t_list	*new;

	tmp = f(lst);
	if (!(head = (t_list *)malloc(sizeof((tmp->content_size)))))
		return (NULL);
	head->content = tmp->content;
	head->next = NULL;
	begin = head;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst);
		if (!(new = (t_list *)malloc(sizeof((tmp->content_size)))))
			return (NULL);
		new->content = tmp->content;
		new->next = NULL;
		head->next = new;
		head = new;
		lst = lst->next;
	}
	return (begin);
}
