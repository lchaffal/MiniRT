/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_noreal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:28:35 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/16 13:28:36 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	move_light(t_obj_light *obj, double world_to_cam[4][4])
{
	obj->position = vector_times_mat(obj->position, world_to_cam);
}
