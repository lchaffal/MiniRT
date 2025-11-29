/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_autre.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:01:03 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 09:01:03 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vector	intersection_error(void *obj, t_ray ray)
{
	(void)ray;
	(void)obj;
	error(ERROR_BAD_INTERSECTION);
	return (create_vector(INFINITY, INFINITY, INFINITY, 1));
}

t_vector	intersection_na(void *obj, t_ray ray)
{
	(void)ray;
	(void)obj;
	return (create_vector(INFINITY, INFINITY, INFINITY, 1));
}
