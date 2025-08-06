/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:27:21 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/19 14:05:19 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		q;
	size_t	i;

	if (dest == src)
		return (dest);
	if (dest < src && dest + n > src)
		q = 0;
	else
		q = 1;
	i = 0;
	while (q == 0 && i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	while (q == 1 && i < n)
	{
		*(char *)(dest + n - i - 1) = *(char *)(src + n - i - 1);
		i++;
	}
	return (dest);
}
