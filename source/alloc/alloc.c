/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:56:52 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 15:58:56 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
#include "../config/config_function.h"

void	alloc(t_alloc *_alloc)
{
	if (_alloc->identifier[0] == 0)
	{
		if (file_read_type(open(filename(0), O_RDONLY), _alloc) == 1)
			error(ERROR_BAD_TYPE);
		alloc(_alloc);
	}
	else if (_alloc->identifier[_alloc->index] != 0)
	{
		g_falloc[_alloc->identifier[_alloc->index]](_alloc);
	}
	else
	{
		if (file_read_value(open(filename(0), O_RDONLY), _alloc) == 1)
			error(ERROR_BAD_VALUE);
		if (_alloc->number[g_ambient_id] != 1
			|| _alloc->number[g_camera_id] != 1)
			error(ERROR_MISSING_MDTR);
		malloc_window(_alloc);
	}
}
