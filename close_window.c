/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:33:18 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/13 12:33:51 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	escape_pressed(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
	{
		mlx_loop_end(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}

int	close_mouse(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
