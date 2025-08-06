/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:06:06 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/06 12:27:47 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include "libft/libft.h"
# include <math.h>

typedef struct	s_vector {
	double	x;
	double	y;
	double	z;
}	t_vector;

//object can be:
//spheres, planes and cylinders
typedef struct	s_object {
	char	identifier;
	t_vector	point;
	t_vector	direction; //only relevant for planes and cylinders
	double	diameter; //only relevant for spheres and cylinders
	double	height; //only relevant for cylinders
	int	color[3];
}	t_object;

typedef struct s_lighting {
	t_vector	point;
	double	ratio;
	int	color[3];
}	t_lighting;

typedef struct s_camera {
	t_vector	point;
	t_vector	direction;
	int	fov;
}	t_camera;

typedef struct s_light {
	t_vector	point;
	double	brightness;
	int	color[3]; //only for bonuses
}	t_light;

#endif
