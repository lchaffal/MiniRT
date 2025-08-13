/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:06:06 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/13 12:40:04 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define D 1 //distance between camera and screen
# define WIDTH 1000
# define HEIGHT 1000

# include <unistd.h>
# include "libft/libft.h"
# include <math.h>
# include "minilibx-linux/mlx.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_data;

typedef struct	s_vector {
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct	s_matrix44 {
	double	row1[4];
	double	row2[4];
	double	row3[4];
	double	row4[4];
} t_matrix44;

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

int	escape_pressed(int keycode, t_vars *vars);
int	close_mouse(t_vars *vars);

#endif
