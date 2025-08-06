/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:47:04 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:02 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	cursor;

	if (!lst)
		return ;
	cursor = *lst;
	while (cursor.next)
	{
		(*f)(cursor.content);
		cursor = *cursor.next;
	}
	(*f)(cursor.content);
}
