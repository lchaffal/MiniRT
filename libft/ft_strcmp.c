/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:46:09 by gromit            #+#    #+#             */
/*   Updated: 2025/01/17 14:47:46 by gromit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		ans;

	ans = 0;
	if (!s1[0])
		ans--;
	if (!s2[0])
		ans++;
	i = 0;
	while (ans == 0 && (s1[i] || s2[i]))
	{
		ans = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (ans);
}
