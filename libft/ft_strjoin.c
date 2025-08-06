/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:42:08 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/13 09:48:25 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ans;

	i = ft_strlen(s1) + ft_strlen(s2);
	ans = malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (0);
	ans[i] = 0;
	i = 0;
	while (s1 && s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		ans[i + j] = s2[j];
		j++;
	}
	return (ans);
}
