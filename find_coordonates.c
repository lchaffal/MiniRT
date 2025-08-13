/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coordonates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:22:55 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/13 16:56:35 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

long double	find_coordonates(int x, int y)
{
	t_vector point;
	point.f[0] =  (2 * (x + 0.5) / (float)WIDTH - 1) * ((float)WIDTH / (float)HEIGHT) * tan(FOV * (M_PI / 360));
	point.f[1] = (1 - 2 * (y + 0.5) / (float)HEIGHT) * tan(FOV * (M_PI / 360));
	point.f[2] = 1;

	point.f[3] = 0; // pading

	return (point.ld);
}

/*double	**find_world_to_cam(t_camera cam)*/
/*{*/
/*	t_vector	v;*/
/**/
/*	v = (t_vector)find_coordonates(3, 3);*/
/*}*/
