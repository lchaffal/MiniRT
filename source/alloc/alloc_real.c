/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_real.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:57:09 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:57:12 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	alloc_plane(t_alloc *_alloc)
{
	t_obj_plane	plane;

	ft_bzero(&plane, sizeof(t_obj_plane));
	plane.identifier = g_plane_id;
	_alloc->obj[_alloc->index] = &plane;
	_alloc->index += 1;
	alloc(_alloc);
}

void	alloc_sphere(t_alloc *_alloc)
{
	t_obj_sphere	sphere;

	ft_bzero(&sphere, sizeof(t_obj_sphere));
	sphere.identifier = g_sphere_id;
	_alloc->obj[_alloc->index] = &sphere;
	_alloc->index += 1;
	alloc(_alloc);
}

void	alloc_cylinder(t_alloc *_alloc)
{
	t_obj_cylinder	cylinder;

	ft_bzero(&cylinder, sizeof(t_obj_cylinder));
	cylinder.identifier = g_cylinder_id;
	_alloc->obj[_alloc->index] = &cylinder;
	_alloc->index += 1;
	alloc(_alloc);
}
