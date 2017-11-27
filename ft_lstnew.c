#include <stdlib.h>
#include <string.h>
#include "libft.h"


t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(list->content = (void *)malloc(content_size)))
		{
			free(list);
			return (NULL);
		}
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}

	list->next = NULL;
	return (list);
}
