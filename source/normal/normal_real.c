/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_real.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:28:54 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/16 13:28:54 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vector	normal_cylinder(t_obj_cylinder *obj, t_vector point)
{
	t_vector		normal;
	t_vector		u;
	double			h;

	u = linear_combination(point, obj->position, 1, -1);
	h = scalar_product(u, obj->orientation);
	normal = linear_combination(obj->position,
			obj->orientation, 1, h);
	normal = linear_combination(point, normal, 1, -1);
	normalize(&normal);
	return (normal);
}

t_vector	normal_plane(t_obj_plane *obj, t_vector point)
{
	(void)point;
	return (obj->orientation);
}

t_vector	normal_sphere(t_obj_sphere *obj, t_vector point)
{
	t_vector	normal;

	normal = linear_combination(obj->position, point, -1, 1);
	normalize(&normal);
	return (normal);
}
