/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:00:56 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 09:00:56 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
#include "../config/config_function.h"

t_vector	intersection(void *obj, t_ray ray)
{
	return (g_fintersection[((t_obj_dummy *)obj)->identifier](obj, ray));
}
