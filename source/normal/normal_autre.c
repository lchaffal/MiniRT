/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_autre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:00:22 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 09:00:23 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vector	normal_error(void *obj, t_vector point)
{
	(void)obj;
	(void)point;
	error(ERROR_BAD_NORMAL);
	return (create_vector(INFINITY, INFINITY, INFINITY, 1));
}

t_vector	normal_na(void *obj, t_vector point)
{
	(void)obj;
	(void)point;
	return (create_vector(INFINITY, INFINITY, INFINITY, 1));
}
