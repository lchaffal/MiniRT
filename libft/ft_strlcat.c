/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:01:56 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/12 16:29:38 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (dst[i])
		i++;
	k = 0;
	while (src[k] && (i + k < siz - 1) && siz)
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i + k < siz)
		dst[i + k] = 0;
	k = ft_strlen(src);
	if (siz > i)
		return (k + i);
	else
		return (k + siz);
}
