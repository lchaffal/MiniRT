/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:06:06 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/13 16:59:33 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define D 1 //distance between camera and screen
# define WIDTH 1000
# define HEIGHT 1000
# define FOV 70

# include <unistd.h>
# include "libft/libft.h"
# include <math.h>
# include "minilibx/mlx.h"

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

typedef struct	s_coord {
	float	x;
	float	y;
	float	z;
}	t_coord;

typedef union {
	float f[4];           // 4 floats (4 × 32 bits = 128 bits)
	t_coord	c;
	long double ld;       // 1 long double (128 bits, platform-dependent)
} t_vector;


//object can be:
//spheres, planes and cylinders
typedef struct	s_object {
	char	identifier;
	t_vector	point;
	t_vector	direction; //only relevant for planes and cylinders
	float	diameter; //only relevant for spheres and cylinders
	float	height; //only relevant for cylinders
	int	color[3];
}	t_object;

typedef struct s_lighting {
	t_vector	point;
	float	ratio;
	int	color[3];
}	t_lighting;

typedef struct s_camera {
	t_vector	point;
	t_vector	direction;
	float	fov;
}	t_camera;

typedef struct s_light {
	t_vector	point;
	float	brightness;
	int	color[3]; //only for bonuses
}	t_light;

int	escape_pressed(int keycode, t_vars *vars);
int	close_mouse(t_vars *vars);

#endif
