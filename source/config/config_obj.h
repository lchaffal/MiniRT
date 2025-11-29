/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_obj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:55:44 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:55:45 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_OBJ_H
# define CONFIG_OBJ_H

# include "config.h"
# include "config_typedef.h"

// ANY OBJECT NEEDS TO START LIKE THE DUMMY STURCT.
// COLOR IS REQUIRED IN ANY CASE !!

extern const unsigned char		g_dummy_id;
extern const unsigned long long	g_dummy_name;
typedef struct s_obj_dummy
{
	unsigned char				identifier;
	t_vector					color;
}	t_obj_dummy;

extern const unsigned char		g_ambient_id;
extern const unsigned long long	g_ambient_name;
//typedef struct s_obj_ambient
//{
//	unsigned char				identifier;
//	t_vector					color;
//	double						ratio;
//}	t_obj_ambient;

extern const unsigned char		g_camera_id;
extern const unsigned long long	g_camera_name;
//typedef struct s_obj_camera
//{
//	unsigned char				identifier;
//	t_vector					color;
//	t_vector					position;
//	t_vector					orientation;
//	double						fov;
//}	t_obj_camera;

extern const unsigned char		g_light_id;
extern const unsigned long long	g_light_name;
typedef struct s_obj_light
{
	unsigned char				identifier;
	t_vector					color;
	t_vector					position;
	double						brightness;
}	t_obj_light;

extern const unsigned char		g_plane_id;
extern const unsigned long long	g_plane_name;
typedef struct s_obj_plane
{
	unsigned char				identifier;
	t_vector					color;
	t_vector					position;
	t_vector					orientation;
}	t_obj_plane;

extern const unsigned char		g_sphere_id;
extern const unsigned long long	g_sphere_name;
typedef struct s_obj_sphere
{
	unsigned char				identifier;
	t_vector					color;
	t_vector					position;
	double						diameter;
}	t_obj_sphere;

extern const unsigned char		g_cylinder_id;
extern const unsigned long long	g_cylinder_name;
typedef struct s_obj_cylinder
{
	unsigned char				identifier;
	t_vector					color;
	t_vector					position;
	t_vector					orientation;
	double						diameter;
	double						height;
}	t_obj_cylinder;

extern const unsigned char		*g_objs_id[CONFIG_MAX_TYPE];
extern const unsigned long long	*g_objs_name[CONFIG_MAX_TYPE];

#endif
