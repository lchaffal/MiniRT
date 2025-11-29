/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:36:37 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/23 13:22:44 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vector	create_vector(double x, double y, double z, double w)
{
	t_vector	u;

	ft_bzero(&u, sizeof(t_vector));
	u.x = x;
	u.y = y;
	u.z = z;
	u.w = w;
	return (u);
}

//returns the norm of u
double	norm_of(t_vector u)
{
	return (sqrt(scalar_product(u, u)));
}

//changes u so its norm is equal to 1
void	normalize(t_vector *u)
{
	double	norm;

	norm = norm_of(*u);
	if (norm == 0)
		return ;
	u->x = u->x / norm;
	u->y = u->y / norm;
	u->z = u->z / norm;
}
