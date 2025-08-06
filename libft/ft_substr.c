/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:38:37 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/19 14:19:03 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ans;

	i = ft_strlen(s);
	if (i < start)
	{
		ans = ft_calloc(sizeof(char), 1);
		if (!ans)
			return (0);
		return (ans);
	}
	i -= start;
	if (len < i)
		i = len;
	ans = malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (0);
	ans[i] = 0;
	i = 0;
	while ((s + start)[i] && i < len)
	{
		ans[i] = (s + start)[i];
		i++;
	}
	return (ans);
}
