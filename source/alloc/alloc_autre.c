/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_autre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:56:47 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:56:48 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	alloc_error(t_alloc *_alloc)
{
	(void)_alloc;
	error(ERROR_BAD_ALLOC);
}

void	alloc_na_ambient(t_alloc *_alloc)
{
	t_obj_dummy	dummy;

	ft_bzero(&dummy, sizeof(t_obj_dummy));
	dummy.identifier = g_ambient_id;
	_alloc->obj[_alloc->index] = &dummy;
	_alloc->index += 1;
	alloc(_alloc);
}

void	alloc_na_camera(t_alloc *_alloc)
{
	t_obj_dummy	dummy;

	ft_bzero(&dummy, sizeof(t_obj_dummy));
	dummy.identifier = g_camera_id;
	_alloc->obj[_alloc->index] = &dummy;
	_alloc->index += 1;
	alloc(_alloc);
}
