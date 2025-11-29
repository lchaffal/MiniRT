/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:48:08 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/23 15:58:42 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	loading(int i)
{
	unsigned char	bar;
	unsigned char	empty;

	bar = i * 70 / HEIGHT;
	empty = 70 - bar;
	ft_putstr_fd("\rLoading [", 1);
	while (bar > 0)
	{
		ft_putstr_fd("#", 1);
		bar--;
	}
	while (empty > 0)
	{
		ft_putstr_fd(" ", 1);
		empty--;
	}
	ft_putstr_fd("]", 1);
}
