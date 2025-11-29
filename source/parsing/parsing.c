/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:05:16 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 15:35:21 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	try_get_type(t_alloc *_alloc,
		unsigned char *buffer_data, unsigned short *buffer_size,
		unsigned char *_error)
{
	if (*buffer_size != 0)
	{
		if (*((unsigned long long *)buffer_data) == g_ambient_name)
			_alloc->identifier[_alloc->index] = g_ambient_id;
		else if (*((unsigned long long *)buffer_data) == g_camera_name)
			_alloc->identifier[_alloc->index] = g_camera_id;
		else if (*((unsigned long long *)buffer_data) == g_light_name)
			_alloc->identifier[_alloc->index] = g_light_id;
		else if (*((unsigned long long *)buffer_data) == g_plane_name)
			_alloc->identifier[_alloc->index] = g_plane_id;
		else if (*((unsigned long long *)buffer_data) == g_sphere_name)
			_alloc->identifier[_alloc->index] = g_sphere_id;
		else if (*((unsigned long long *)buffer_data) == g_cylinder_name)
			_alloc->identifier[_alloc->index] = g_cylinder_id;
		else
			*_error = 1;
		_alloc->index += 1;
		if (_alloc->index > CONFIG_MAX_OBJ)
		{
			*_error = 1;
			ft_putstr_fd(ERROR_BAD_NUMBER, 2);
		}
		ft_bzero(buffer_data, ft_strlen((char *)buffer_data));
		*buffer_size = 0;
	}
}

void	try_get_value(t_alloc *_alloc,
		unsigned char *buffer_data, unsigned short *buffer_size,
		unsigned char *_error)
{
	if (*buffer_size != 0)
	{
		if (_alloc->identifier[_alloc->index] == g_ambient_id)
			parsing_ambient(_alloc, buffer_data, _error);
		else if (_alloc->identifier[_alloc->index] == g_camera_id)
			parsing_camera(_alloc, buffer_data, _error);
		else if (_alloc->identifier[_alloc->index] == g_light_id)
			parsing_light(_alloc, buffer_data, _error);
		else if (_alloc->identifier[_alloc->index] == g_plane_id)
			parsing_plane(_alloc, buffer_data, _error);
		else if (_alloc->identifier[_alloc->index] == g_sphere_id)
			parsing_sphere(_alloc, buffer_data, _error);
		else if (_alloc->identifier[_alloc->index] == g_cylinder_id)
			parsing_cylinder(_alloc, buffer_data, _error);
		else
			*_error = 1;
		_alloc->index += 1;
		ft_bzero(buffer_data, ft_strlen((char *)buffer_data));
		*buffer_size = 0;
	}
}

char	*filename(char *_path)
{
	static char		path[255];
	unsigned int	loop;

	loop = 0;
	if (!path[0])
	{
		while (_path[loop] != 0)
		{
			path[loop] = _path[loop];
			loop += 1;
		}
		path[loop] = 0;
		if (loop < 3)
			error(ERROR_BAD_FILENAME);
		if ((*(unsigned int *)&path[loop - 3]) != (*(unsigned int *)".rt\0"))
			error(ERROR_BAD_FILEEXT);
	}
	return (path);
}
