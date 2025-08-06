/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:33:31 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/13 11:41:35 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ans;
	int		i;

	i = ft_strlen(s);
	ans = malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (0);
	ans[i] = 0;
	while (i--)
		ans[i] = (*f)(i, s[i]);
	return (ans);
}
