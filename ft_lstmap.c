#include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*cur;

	if (!lst)
		return (lst);
	lst2 = ft_lstnew(f(lst->content));
	lst = lst->next;
	cur = lst2;
	if (lst2)
		while (lst)
		{
			cur->next = ft_lstnew(f(lst->content));
			cur = cur->next;
			lst = lst->next;
			if (cur)
				continue ;
			ft_lstclear(&lst2, del);
			break ;
		}
	return (lst2);
}
