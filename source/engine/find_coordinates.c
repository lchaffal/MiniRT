/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:22:55 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/09 11:03:38 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
#include <math.h>

//x and y are the coordonates of screen pixel
t_vector	find_coordinates(int x, int y, double fov)
{
	t_vector	point;
	double		ratio;
	double		fov_coeff;

	ratio = (double)WIDTH / (double)HEIGHT;
	fov_coeff = tan(fov / 2 * M_PI / 180);
	point.x = (2 * (x + 0.5) / (double)WIDTH - 1) * ratio * fov_coeff;
	point.y = (1 - 2 * (y + 0.5) / (double)HEIGHT) * fov_coeff;
	point.z = -1;
	point.w = 0;
	return (point);
}

static void	put_vector(double world_to_cam[4][4], t_vector u,
				unsigned int column)
{
	world_to_cam[0][column] = u.x;
	world_to_cam[1][column] = u.y;
	world_to_cam[2][column] = u.z;
}

//Calculates the matrix needed to convert an object from world to camera
//First creates a base based on the camera orientation
//then translates it correctly
//using camera's position
void	find_world_to_cam(t_vector *position, t_vector *orientation,
		double world_to_cam[4][4])
{
	t_vector	tmp;
	t_vector	right;
	t_vector	up;
	t_vector	front;

	front = create_vector(-orientation->x,
			-orientation->y, -orientation->z, 0);
	tmp = create_vector(0, 1, 0, 0);
	if (front.y == 1 || front.y == -1)
		tmp = create_vector(1, 0, 0, 0);
	right = vector_product(front, tmp);
	normalize(&right);
	up = vector_product(right, front);
	normalize(&up);
	put_vector(world_to_cam, right, 0);
	put_vector(world_to_cam, up, 1);
	put_vector(world_to_cam, front, 2);
	tmp = create_vector(-position->x,
			-position->y, -position->z, 0);
	world_to_cam[3][0] = scalar_product(tmp, right);
	world_to_cam[3][1] = scalar_product(tmp, up);
	world_to_cam[3][2] = scalar_product(tmp, front);
	tmp = create_vector(0, 0, 0, 1);
	put_vector(world_to_cam, tmp, 3);
	world_to_cam[3][3] = 1;
}
