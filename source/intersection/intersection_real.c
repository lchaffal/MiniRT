/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_real.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:27:23 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/16 13:27:25 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vector	intersection_cylinder(t_obj_cylinder *obj, t_ray ray)
{
	double			abc[3];
	double			delta;
	t_vector		minus_a_squared;

	minus_a_squared = create_vector(1
			- obj->orientation.x * obj->orientation.x,
			1 - obj->orientation.y * obj->orientation.y,
			1 - obj->orientation.z * obj->orientation.z, 0);
	compute_cylinder_a(&abc[0], obj, ray, minus_a_squared);
	compute_cylinder_b(&abc[1], obj, ray, minus_a_squared);
	compute_cylinder_c(&abc[2], obj, ray, minus_a_squared);
	delta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (delta < 0)
		return (create_vector(INFINITY, INFINITY, INFINITY, 1));
	else if (delta == 0)
		return (linear_combination(ray.origin, ray.direction,
				1, -abc[1] / (2 * abc[0])));
	else
		return (select_cylinder_answer(abc, delta, ray, obj));
}

t_vector	intersection_plane(t_obj_plane *obj, t_ray ray)
{
	double	t;

	if (scalar_product(obj->orientation, ray.direction) == 0)
		return (create_vector(INFINITY, INFINITY, INFINITY, 1));
	t = scalar_product(obj->orientation,
			linear_combination(obj->position, ray.origin,
				1, -1))
		/ scalar_product(obj->orientation, ray.direction);
	if (t > 0)
		return (linear_combination(ray.origin, ray.direction, 1, t));
	else
		return (create_vector(INFINITY, INFINITY, INFINITY, 1));
}

t_vector	intersection_sphere(t_obj_sphere *obj, t_ray ray)
{
	double		delta;
	double		abc[3];
	t_vector	point;

	point = linear_combination(ray.origin,
			obj->position, 1, -1);
	abc[0] = scalar_product(ray.direction, ray.direction);
	abc[1] = 2 * scalar_product(point, ray.direction);
	abc[2] = scalar_product(point, point)
		- pow(obj->diameter / 2, 2);
	delta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (delta < 0)
		return (create_vector(INFINITY, INFINITY, INFINITY, 1));
	else if (delta == 0)
		return (linear_combination(ray.origin, ray.direction,
				1, -abc[1] / (2 * abc[0])));
	else
		return (select_sphere_answer(abc, delta, ray));
}
