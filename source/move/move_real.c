/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_real.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:28:40 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/16 13:28:41 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	move_plane(t_obj_plane *obj, double world_to_cam[4][4])
{
	normalize(&obj->orientation);
	obj->position = vector_times_mat(obj->position, world_to_cam);
	obj->orientation = vector_times_mat(obj->orientation, world_to_cam);
}

void	move_sphere(t_obj_sphere *obj, double world_to_cam[4][4])
{
	obj->position = vector_times_mat(obj->position, world_to_cam);
}

void	move_cylinder(t_obj_cylinder *obj, double world_to_cam[4][4])
{
	obj->position = vector_times_mat(obj->position, world_to_cam);
	obj->orientation = vector_times_mat(obj->orientation, world_to_cam);
	normalize(&obj->orientation);
}
