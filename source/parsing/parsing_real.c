/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_real.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:05:33 by lmarion           #+#    #+#             */
/*   Updated: 2025/10/29 16:03:59 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parsing_plane(t_alloc *_alloc,
		unsigned char *buffer_data, unsigned char *_error)
{
	t_obj_plane	*plane;

	obj_limit(_alloc, g_plane_id, "plane", _error);
	plane = (t_obj_plane *)_alloc->obj[_alloc->index];
	plane->position.x = ft_atod(buffer_data, 0, _error);
	plane->position.y = ft_atod(buffer_data, 1, _error);
	plane->position.z = ft_atod(buffer_data, 2, _error);
	plane->position.w = 1;
	plane->orientation.x = ft_atod(buffer_data, 3, _error);
	plane->orientation.y = ft_atod(buffer_data, 4, _error);
	plane->orientation.z = ft_atod(buffer_data, 5, _error);
	plane->orientation.w = 0;
	norm_limit(&plane->orientation, "plane", _error);
	plane->color.x = ft_atod(buffer_data, 6, _error);
	plane->color.y = ft_atod(buffer_data, 7, _error);
	plane->color.z = ft_atod(buffer_data, 8, _error);
	plane->color.w = 0;
	if (*_error != 1)
	{
		ft_atod(buffer_data, 9, _error);
		*_error = !*_error;
	}
}

void	parsing_sphere(t_alloc *_alloc,
		unsigned char *buffer_data, unsigned char *_error)
{
	t_obj_sphere	*sphere;

	obj_limit(_alloc, g_sphere_id, "sphere", _error);
	sphere = (t_obj_sphere *)_alloc->obj[_alloc->index];
	sphere->position.x = ft_atod(buffer_data, 0, _error);
	sphere->position.y = ft_atod(buffer_data, 1, _error);
	sphere->position.z = ft_atod(buffer_data, 2, _error);
	printf("\n%f", sphere->position.z);
	sphere->position.w = 1;
	sphere->diameter = ft_atod(buffer_data, 3, _error);
	sphere->color.x = ft_atod(buffer_data, 4, _error);
	sphere->color.y = ft_atod(buffer_data, 5, _error);
	sphere->color.z = ft_atod(buffer_data, 6, _error);
	sphere->color.w = 0;
	if (*_error != 1)
	{
		ft_atod(buffer_data, 7, _error);
		*_error = !*_error;
	}
}

void	parsing_cylinder(t_alloc *_alloc,
		unsigned char *buffer_data, unsigned char *_error)
{
	t_obj_cylinder	*cylinder;

	obj_limit(_alloc, g_cylinder_id, "cylinder", _error);
	cylinder = (t_obj_cylinder *)_alloc->obj[_alloc->index];
	cylinder->position.x = ft_atod(buffer_data, 0, _error);
	cylinder->position.y = ft_atod(buffer_data, 1, _error);
	cylinder->position.z = ft_atod(buffer_data, 2, _error);
	cylinder->position.w = 1;
	cylinder->orientation.x = ft_atod(buffer_data, 3, _error);
	cylinder->orientation.y = ft_atod(buffer_data, 4, _error);
	cylinder->orientation.z = ft_atod(buffer_data, 5, _error);
	cylinder->orientation.w = 0;
	norm_limit(&cylinder->orientation, "cylinder", _error);
	cylinder->diameter = ft_atod(buffer_data, 6, _error);
	cylinder->height = ft_atod(buffer_data, 7, _error);
	cylinder->color.x = ft_atod(buffer_data, 8, _error);
	cylinder->color.y = ft_atod(buffer_data, 9, _error);
	cylinder->color.z = ft_atod(buffer_data, 10, _error);
	cylinder->color.w = 0;
	if (*_error != 1)
	{
		ft_atod(buffer_data, 11, _error);
		*_error = !*_error;
	}
}
