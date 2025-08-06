/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:01:32 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/19 17:06:46 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_size(int n, int *size, int *q)
{
	int	i;

	i = n;
	*size = 0;
	while (n)
	{
		*size += 1;
		n /= 10;
	}
	if (i < 0)
	{
		*size += 1;
		*q = 1;
	}
	if (i == 0)
		*size = 1;
	return (ft_calloc(sizeof(char), (*size + 1)));
}

char	*ft_itoa(int n)
{
	char	*number;
	int		size;
	int		q;

	q = 0;
	number = get_size(n, &size, &q);
	if (!number)
		return (0);
	number[size] = 0;
	if (n == -2147483648 && size--)
	{
		number[size] = 56;
		n /= 10;
	}
	if (n < 0)
		n *= -1;
	while (size--)
	{
		number[size] = (n % 10) + 48;
		n /= 10;
	}
	if (q == 1)
		number[0] = '-';
	return (number);
}
