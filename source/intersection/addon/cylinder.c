/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:27:08 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/16 13:27:10 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"

t_vector	select_cylinder_answer(double abc[3], double delta,
					t_ray ray, t_obj_cylinder *cyl)
{
	double		t1;
	double		t2;
	t_vector	answer;

	t1 = (-abc[1] + sqrt(delta)) / (2 * abc[0]);
	t2 = (-abc[1] - sqrt(delta)) / (2 * abc[0]);
	if (t1 < 0 && t2 < 0)
		answer = create_vector(INFINITY, INFINITY, INFINITY, 0);
	else
	{
		if (t1 > t2)
		{
			abc[0] = t1;
			t1 = t2;
			t2 = abc[0];
		}
		answer = try_cylinder_answers(t1, t2, ray, cyl);
	}
	return (answer);
}

t_vector	try_cylinder_answers(double t1, double t2,
					t_ray ray, t_obj_cylinder *cyl)
{
	t_vector	answer;
	double		tmp;

	answer = linear_combination(ray.origin, ray.direction, 1, t1);
	tmp = scalar_product(linear_combination(answer,
				cyl->position, 1, -1), cyl->orientation);
	if (t1 < 0 || tmp < 0 || tmp > cyl->height)
	{
		answer = linear_combination(ray.origin, ray.direction, 1, t2);
		tmp = scalar_product(linear_combination(answer,
					cyl->position, 1, -1), cyl->orientation);
		if (tmp < 0 || tmp > cyl->height)
			answer = create_vector(INFINITY, INFINITY, INFINITY, 0);
	}
	return (answer);
}

void	compute_cylinder_a(double *a, t_obj_cylinder *cyl,
				t_ray ray, t_vector minus_a_squared)
{
	t_vector	tmp1;
	t_vector	tmp2;

	tmp2 = create_vector(ray.direction.x * ray.direction.x,
			ray.direction.y * ray.direction.y,
			ray.direction.z * ray.direction.z, 0);
	*a = scalar_product(minus_a_squared, tmp2);
	tmp1 = create_vector(cyl->orientation.x * cyl->orientation.y,
			cyl->orientation.x * cyl->orientation.z,
			cyl->orientation.y * cyl->orientation.z, 0);
	tmp2 = create_vector(ray.direction.x * ray.direction.y,
			ray.direction.x * ray.direction.z,
			ray.direction.y * ray.direction.z, 0);
	*a = *a - 2 * scalar_product(tmp1, tmp2);
}

void	compute_cylinder_b(double *b, t_obj_cylinder *cyl,
				t_ray ray, t_vector minus_a_squared)
{
	t_vector	tmp1;
	t_vector	tmp2;
	t_vector	ec;

	ec = linear_combination(ray.origin, cyl->position, 1, -1);
	tmp2 = create_vector(ray.direction.x * ray.direction.x,
			ray.direction.y * ray.direction.y,
			ray.direction.z * ray.direction.z, 0);
	tmp2 = create_vector(ec.x * ray.direction.x,
			ec.y * ray.direction.y,
			ec.z * ray.direction.z, 0);
	*b = scalar_product(minus_a_squared, tmp2);
	tmp1 = create_vector(cyl->orientation.x * cyl->orientation.y,
			cyl->orientation.x * cyl->orientation.z,
			cyl->orientation.y * cyl->orientation.z, 0);
	tmp2 = create_vector(ec.x * ray.direction.y
			+ ec.y * ray.direction.x,
			ec.x * ray.direction.z + ec.z * ray.direction.x,
			ec.y * ray.direction.z + ec.z * ray.direction.y, 0);
	*b = *b - scalar_product(tmp1, tmp2);
	*b = 2 * *b;
}

void	compute_cylinder_c(double *c, t_obj_cylinder *cyl,
				t_ray ray, t_vector minus_a_squared)
{
	t_vector	tmp1;
	t_vector	tmp2;
	t_vector	ec;

	ec = linear_combination(ray.origin, cyl->position, 1, -1);
	tmp1 = create_vector(cyl->orientation.x * cyl->orientation.y,
			cyl->orientation.x * cyl->orientation.z,
			cyl->orientation.y * cyl->orientation.z, 0);
	tmp2 = create_vector(ec.x * ec.x, ec.y * ec.y, ec.z * ec.z, 0);
	*c = scalar_product(minus_a_squared, tmp2);
	tmp1 = create_vector(cyl->orientation.x * cyl->orientation.y,
			cyl->orientation.x * cyl->orientation.z,
			cyl->orientation.y * cyl->orientation.z, 0);
	tmp2 = create_vector(ec.x * ec.y, ec.x * ec.z, ec.y * ec.z, 0);
	*c = *c - 2 * scalar_product(tmp1, tmp2);
	*c = *c - (cyl->diameter * 0.5) * (cyl->diameter * 0.5);
}
