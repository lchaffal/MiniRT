/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:28:14 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/16 13:28:15 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "Error\n", 6);
	exit(1);
}

void	move_everything(t_alloc *objs_list, double world_to_cam[4][4])
{
	unsigned int	number;

	number = objs_list->index;
	while (number != 0)
	{
		number -= 1;
		move(objs_list->obj[number], world_to_cam);
	}
}

void	*intersection_everything(t_ray _ray,
		t_vector *intersection_point, t_alloc *objs_list)
{
	t_vector		tmp;
	void			*intersected_obj;
	double			distance_min;
	unsigned int	number;

	distance_min = INFINITY;
	intersected_obj = NULL;
	number = objs_list->index;
	while (number > 0)
	{
		number--;
		tmp = intersection(objs_list->obj[number], _ray);
		if (norm_of(tmp) < distance_min)
		{
			*intersection_point = tmp;
			intersected_obj = objs_list->obj[number];
			distance_min = norm_of(tmp);
		}
	}
	return (intersected_obj);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	*(unsigned int *)(img->data + (y * img->size_line + x * (img->bpp / 8)))
		= color;
}

int	create_color(t_vector color)
{
	return (0 << 24 | (int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}
