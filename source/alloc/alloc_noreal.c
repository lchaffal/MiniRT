/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_noreal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:57:01 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:57:03 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	alloc_light(t_alloc *_alloc)
{
	t_obj_light	light;

	ft_bzero(&light, sizeof(t_obj_light));
	light.identifier = g_light_id;
	_alloc->obj[_alloc->index] = &light;
	_alloc->index += 1;
	alloc(_alloc);
}
