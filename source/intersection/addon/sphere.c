/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:27:13 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/16 13:27:14 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

t_vector	select_sphere_answer(double abc[3], double delta, t_ray ray)
{
	double	t1;
	double	t2;
	double	tmp;

	t1 = (-abc[1] + sqrt(delta)) / (2 * abc[0]);
	t2 = (-abc[1] - sqrt(delta)) / (2 * abc[0]);
	if (t1 < 0 && t2 < 0)
		return (create_vector(INFINITY, INFINITY, INFINITY, 1));
	else
	{
		if (t1 > t2)
		{
			tmp = t1;
			t1 = t2;
			t2 = tmp;
		}
		if (t1 < 0)
			return (linear_combination(ray.origin, ray.direction, 1, t2));
		else
			return (linear_combination(ray.origin, ray.direction, 1, t1));
	}
}
