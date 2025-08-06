/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:20:46 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/06 12:29:50 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

//returns the norm of u
double	norm(t_vector u)
{
	double	norm;

        norm = sqrt(square(u.x) + square(u.y) + square(u.z));
        return (norm);
}

//changes u so its norm is equal to 1
t_vector	normalize(t_vector u)
{

}
