/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:00:41 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/13 17:09:30 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

long double	vector_product(t_vector u, t_vector v)
{
	t_vector	w;

	w.c.x = u.c.y * v.c.z - u.c.z * v.c.y;
	w.c.y = u.c.z * v.c.x - u.c.x * v.c.z;
	w.c.z = u.c.x * v.c.y - u.c.y * v.c.x;
	return(w.ld);
}

//returns the scalar product of u and v
float	scalar_product(t_vector u, t_vector v)
{
	return (u.c.x * v.c.x + u.c.y * v.c.y + u.c.z * v.c.z);
}

//returns the norm of u
float	norm_of(t_vector u)
{
	return (sqrt(scalar_product(u, u)));
}

//changes u so its norm is equal to 1
void	normalize(t_vector *u)
{
	float	norm;

	norm = norm_of(*u);
	u->c.x = u->c.x / norm;
	u->c.y = u->c.y / norm;
	u->c.z = u->c.z / norm;
}
