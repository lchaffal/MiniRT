/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:54:26 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/19 15:36:30 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				ans;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	ans = 0;
	if (*p1 == 0 && n > 0)
		ans--;
	if (*p2 == 0 && n > 0)
		ans++;
	i = 0;
	while (ans == 0 && i < n)
	{
		ans = *(p1 + i) - *(p2 + i);
		i++;
	}
	return (ans);
}
