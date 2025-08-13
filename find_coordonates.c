/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coordonates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:22:55 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/13 16:02:01 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	find_coordonates(int x, int y)
{
	t_vector point;
	point.x =  (2 * (x + 0.5) / (float)WIDTH - 1) * ((float)WIDTH / (float)HEIGHT) * tan(FOV * (M_PI / 360));
	point.y = (1 - 2 * (y + 0.5) / (float)HEIGHT) * tan(FOV * (M_PI / 360));
	point.z = 1;

	return (point);
}
