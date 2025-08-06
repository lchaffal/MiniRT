/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:29:18 by lchaffal          #+#    #+#             */
/*   Updated: 2024/11/14 12:14:57 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int			sign;
	int			n;
	int			i;

	i = 0;
	n = 0;
	sign = 1;
	while ((8 < nptr[i] && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	else if (!(47 < nptr[i] && nptr[i] < 58))
		return (0);
	while (47 < nptr[i] && nptr[i] < 58)
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	n = n * sign;
	return (n);
}
