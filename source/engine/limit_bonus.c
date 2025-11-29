/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:52:37 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 14:52:40 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	norm_limit(t_vector *orientation, char *label, unsigned char *_error)
{
	(void)label;
	(void)_error;
	normalize(orientation);
}

void	obj_limit(t_alloc *alloc, unsigned char id, char *label,
		unsigned char *_error)
{
	alloc->number[id] += 1;
	if (ft_capalpha(g_objs_name[id][0]) == 1)
	{
		if (alloc->number[id] == 2 && id != g_light_id)
		{
			write(2, ERROR_TOO_MANY, sizeof(ERROR_TOO_MANY));
			write(2, " (", 2);
			write(2, label, ft_strlen(label));
			write(2, ")\n", 2);
			*_error = 1;
		}
	}
}
