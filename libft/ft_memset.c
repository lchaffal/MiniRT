/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:34:55 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/19 11:13:14 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*ans;

	ans = s;
	while (n)
	{
		*(unsigned char *)s = (unsigned char)c;
		s++;
		n--;
	}
	return (ans);
}
