/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:04:45 by lchaffal          #+#    #+#             */
/*   Updated: 2025/11/05 13:14:55 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static t_vector	compute_color(t_obj_light *light, void *intersected_obj,
				t_ray _ray, t_ray primary_ray)
{
	double		diffuse_coeff;
	t_vector	_normal;
	t_vector	reflection;
	t_vector	specular;
	t_vector	diffuse;

	_normal = normal(intersected_obj, _ray.origin);
	diffuse_coeff = scalar_product(_ray.direction, _normal);
	if (diffuse_coeff > 0)
	{
		diffuse_coeff /= 4 * M_PI * scalar_product(linear_combination(
					_ray.origin, light->position, 1, -1),
				linear_combination(_ray.origin, light->position, 1, -1));
		diffuse = double_times_vector(light->brightness * diffuse_coeff,
				light->color);
		reflection = linear_combination(double_times_vector(2
					* scalar_product(_ray.direction, _normal), _normal),
				_ray.direction, 1, -1);
		specular = double_times_vector(KS * light->brightness
				* pow(scalar_product(reflection, primary_ray.direction),
					ALPHA), light->color);
		return (linear_combination(diffuse, specular, 1, 1));
	}
	else
		return (create_vector(0, 0, 0, 0));
}

static int	cap_color(t_vector color)
{
	if (color.x > 255)
		color.x = 255;
	if (color.y > 255)
		color.y = 255;
	if (color.z > 255)
		color.z = 255;
	return (create_color(color));
}

static t_vector	light_contribution(t_alloc *objs_list,
				t_obj_light *light, t_pointed_obj intersected_obj,
				t_ray primary_ray)
{
	t_ray			_ray;
	t_pointed_obj	eclipse;
	double			d_max;
	t_vector		tmp;

	_ray.origin = intersected_obj.point;
	_ray.direction = linear_combination(_ray.origin, light->position, -1, 1);
	d_max = norm_of(_ray.direction);
	normalize(&_ray.direction);
	_ray.origin = linear_combination(_ray.origin, _ray.direction, 1, OFFSET);
	eclipse.obj = intersection_everything(_ray, &eclipse.point, objs_list);
	tmp = linear_combination(eclipse.point, _ray.origin, 1, -1);
	if (!eclipse.obj || norm_of(tmp) > d_max)
		return (compute_color(light, intersected_obj.obj, _ray, primary_ray));
	return (create_vector(0, 0, 0, 0));
}

static int	compute_shadow(t_alloc *objs_list,
			t_pointed_obj intersected_obj, t_ray primary_ray)
{
	t_vector		color;
	unsigned int	i;

	if (!intersected_obj.obj)
		return (0);
	i = 0;
	color = double_times_vector(objs_list->ambient.w, objs_list->ambient);
	while (i < objs_list->index)
	{
		if (((t_obj_dummy *)objs_list->obj[i])->identifier == g_light_id)
			color = linear_combination(color,
					light_contribution(objs_list, objs_list->obj[i],
						intersected_obj, primary_ray), 1, 1);
		i++;
	}
	color = linear_combination(color,
			((t_obj_dummy *)intersected_obj.obj)->color, 1,
			objs_list->ambient.w);
	return (cap_color(color));
}

void	compute_image(t_img *img, t_alloc *objs_list)
{
	int				i;
	int				j;
	t_ray			_ray;
	t_pointed_obj	intersected_obj;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			_ray.origin = create_vector(0, 0, 0, 1);
			_ray.direction = linear_combination(_ray.origin,
					find_coordinates(j, i, objs_list->fov), -1, 1);
			normalize(&_ray.direction);
			intersected_obj.obj = intersection_everything(_ray,
					&intersected_obj.point, objs_list);
			my_mlx_pixel_put(img, j, i,
				compute_shadow(objs_list, intersected_obj, _ray));
			j++;
		}
		i++;
		loading(i);
	}
	write(1, "\n", 1);
}
