/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:00:41 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/09 15:37:49 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vector	vector_product(t_vector u, t_vector v)
{
	t_vector	w;

	ft_bzero(&w, sizeof(t_vector));
	w.x = u.y * v.z - u.z * v.y;
	w.y = u.z * v.x - u.x * v.z;
	w.z = u.x * v.y - u.y * v.x;
	w.w = 0;
	return (w);
}

//Returns u * k1 + v * k2
t_vector	linear_combination(t_vector u, t_vector v, double k1, double k2)
{
	t_vector	w;

	ft_bzero(&w, sizeof(t_vector));
	w.x = u.x * k1 + v.x * k2;
	w.y = u.y * k1 + v.y * k2;
	w.z = u.z * k1 + v.z * k2;
	w.w = 1;
	return (w);
}

t_vector	double_times_vector(double f, t_vector u)
{
	t_vector	w;

	ft_bzero(&w, sizeof(t_vector));
	w.x = u.x * f;
	w.y = u.y * f;
	w.z = u.z * f;
	w.w = 1;
	return (w);
}

//returns the scalar product of u and v
double	scalar_product(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vector	vector_times_mat(t_vector u, double m[4][4])
{
	t_vector	v;

	ft_bzero(&v, sizeof(t_vector));
	v.x = u.x * m[0][0] + u.y * m[1][0]
		+ u.z * m[2][0] + u.w * m[3][0];
	v.y = u.x * m[0][1] + u.y * m[1][1]
		+ u.z * m[2][1] + u.w * m[3][1];
	v.z = u.x * m[0][2] + u.y * m[1][2]
		+ u.z * m[2][2] + u.w * m[3][2];
	v.w = u.w;
	return (v);
}
