/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:30:08 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/20 12:31:37 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	friend(t_list **newlst, void (*del)(void *), t_list *node, void *p)
{
	if (!node)
	{
		if (*newlst == 0)
		{
			ft_lstclear(&node, (*del));
			(*del)(p);
		}
		else
		{
			ft_lstclear(newlst, (*del));
			ft_lstclear(&node, (*del));
			(*del)(p);
		}
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node1;
	t_list	*node2;
	t_list	*newlst;
	void	*p;

	if (!lst)
		return (0);
	newlst = 0;
	p = (*f)(lst->content);
	node1 = ft_lstnew(p);
	if (!friend(&newlst, (*del), node1, p))
		return (0);
	newlst = node1;
	while (lst->next)
	{
		lst = lst->next;
		p = (*f)(lst->content);
		node2 = ft_lstnew(p);
		if (!friend(&newlst, (*del), node2, p))
			return (0);
		node1->next = node2;
		node1 = node2;
	}
	return (newlst);
}
