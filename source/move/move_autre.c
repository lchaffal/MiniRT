/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_autre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:59:47 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:59:48 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	move_error(void *obj, double world_to_cam[4][4])
{
	(void)obj;
	(void)world_to_cam;
	error(ERROR_BAD_MOVE);
}

void	move_na(void *obj, double world_to_cam[4][4])
{
	(void)obj;
	(void)world_to_cam;
}
