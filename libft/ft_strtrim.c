/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:48:48 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/19 14:47:47 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, const char *set)
{
	int	i;

	i = 0;
	while (set && set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	void	setup(char const *s1, char const *set, int *i, int *k)
{
	*i = ft_strlen(s1) - 1;
	*k = 0;
	while (is_in(s1[*k], set) || is_in(s1[*i], set))
	{
		if (is_in(s1[*k], set))
			*k += 1;
		if (is_in(s1[*i], set))
			*i -= 1;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	int		j;
	char	*ans;

	setup(s1, set, &i, &k);
	if (i < k)
		ans = ft_calloc(sizeof(char), 1);
	else
		ans = ft_calloc(sizeof(char), i - k + 2);
	if (!ans)
		return (0);
	j = 0;
	while (k <= i)
		ans[j++] = s1[k++];
	ans[k] = 0;
	return (ans);
}
