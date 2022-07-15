/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:38:36 by tkong             #+#    #+#             */
/*   Updated: 2022/07/13 14:44:29 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*cur;

	lst2 = ft_lstnew(f(lst->content));
	lst = lst->next;
	cur = lst2;
	if (lst2)
	{
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
	}
	return (lst2);
}
