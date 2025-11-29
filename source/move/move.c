/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:59:13 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:59:14 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
#include "../config/config_function.h"

void	move(void *obj, double world_to_cam[4][4])
{
	g_fmove[((t_obj_dummy *)obj)->identifier](obj, world_to_cam);
}
