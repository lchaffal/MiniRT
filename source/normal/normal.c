/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:00:17 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 09:00:17 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
#include "../config/config_function.h"

t_vector	normal(void *obj, t_vector point)
{
	return (g_fnormal[((t_obj_dummy *)obj)->identifier](obj, point));
}
