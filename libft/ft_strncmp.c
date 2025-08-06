/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:42:12 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/19 15:11:09 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ans;

	ans = 0;
	if (!s1[0] && n > 0)
		ans--;
	if (!s2[0] && n > 0)
		ans++;
	i = 0;
	while (ans == 0 && (s1[i] || s2[i]) && i < n)
	{
		ans = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (ans);
}
