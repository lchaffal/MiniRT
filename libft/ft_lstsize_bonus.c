/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:23:18 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/19 17:48:21 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	cursor;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	cursor = *lst;
	while (cursor.next != NULL)
	{
		cursor = *cursor.next;
		i++;
	}
	return (i);
}
