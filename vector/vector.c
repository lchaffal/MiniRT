/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:20:46 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/13 11:48:06 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vector	vector_product(t_vector u, t_vector v)
{
	t_vector	w;

	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	return(w);
}

//returns the scalar product of u and v
double	scalar(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

//returns the norm of u
double	norm_of(t_vector u)
{
	return (sqrt(scalar(u, u)));
}

//changes u so its norm is equal to 1
void	normalize(t_vector *u)
{
	double	norm;

	norm = norm_of(*u);
	u->x = u->x / norm;
	u->y = u->y / norm;
	u->z = u->z / norm;
}
