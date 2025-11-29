/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_noreal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:05:26 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 09:05:27 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parsing_ambient(t_alloc *_alloc,
		unsigned char *buffer_data, unsigned char *_error)
{
	obj_limit(_alloc, g_ambient_id, "ambient", _error);
	_alloc->ambient.w = ft_atod(buffer_data, 0, _error);
	_alloc->ambient.x = ft_atod(buffer_data, 1, _error);
	_alloc->ambient.y = ft_atod(buffer_data, 2, _error);
	_alloc->ambient.z = ft_atod(buffer_data, 3, _error);
	if (*_error != 1)
	{
		ft_atod(buffer_data, 4, _error);
		*_error = !*_error;
	}
}

void	parsing_camera(t_alloc *_alloc,
		unsigned char *buffer_data, unsigned char *_error)
{
	t_vector	position;
	t_vector	orientation;

	obj_limit(_alloc, g_camera_id, "camera", _error);
	position.x = ft_atod(buffer_data, 0, _error);
	position.y = ft_atod(buffer_data, 1, _error);
	position.z = ft_atod(buffer_data, 2, _error);
	position.w = 1;
	orientation.x = ft_atod(buffer_data, 3, _error);
	orientation.y = ft_atod(buffer_data, 4, _error);
	orientation.z = ft_atod(buffer_data, 5, _error);
	orientation.w = 0;
	_alloc->fov = ft_atod(buffer_data, 6, _error);
	norm_limit(&orientation, "camera", _error);
	normalize(&orientation);
	find_world_to_cam(&position, &orientation, _alloc->camera);
	if (*_error != 1)
	{
		ft_atod(buffer_data, 7, _error);
		*_error = !*_error;
	}
}

void	parsing_light(t_alloc *_alloc,
		unsigned char *buffer_data, unsigned char *_error)
{
	t_obj_light	*light;

	obj_limit(_alloc, g_light_id, "light", _error);
	light = (t_obj_light *)_alloc->obj[_alloc->index];
	light->position.x = ft_atod(buffer_data, 0, _error);
	light->position.y = ft_atod(buffer_data, 1, _error);
	light->position.z = ft_atod(buffer_data, 2, _error);
	light->position.w = 1;
	light->brightness = ft_atod(buffer_data, 3, _error);
	light->color.x = ft_atod(buffer_data, 4, _error);
	light->color.y = ft_atod(buffer_data, 5, _error);
	light->color.z = ft_atod(buffer_data, 6, _error);
	light->color.w = 0;
	if (*_error != 1)
	{
		ft_atod(buffer_data, 7, _error);
		*_error = !*_error;
	}
}
