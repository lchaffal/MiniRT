/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:55:39 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:55:40 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_FUNCTION_H
# define CONFIG_FUNCTION_H

# include "config.h"
# include "config_typedef.h"

extern void						alloc_error(t_alloc *_alloc);
extern void						alloc_na_ambient(t_alloc *_alloc);
extern void						alloc_na_camera(t_alloc *_alloc);
extern void						alloc_light(t_alloc *_alloc);
extern void						alloc_plane(t_alloc *_alloc);
extern void						alloc_sphere(t_alloc *_alloc);
extern void						alloc_cylinder(t_alloc *_alloc);

extern void						move_error(void *obj,
									double world_to_cam[4][4]);
extern void						move_na(void *obj,
									double world_to_cam[4][4]);
extern void						move_light(void *obj,
									double world_to_cam[4][4]);
extern void						move_sphere(void *obj,
									double world_to_cam[4][4]);
extern void						move_plane(void *obj,
									double world_to_cam[4][4]);
extern void						move_cylinder(void *obj,
									double world_to_cam[4][4]);

extern t_vector					intersection_error(void *obj, t_ray ray);
extern t_vector					intersection_na(void *obj, t_ray ray);
extern t_vector					intersection_sphere(void *obj, t_ray ray);
extern t_vector					intersection_plane(void *obj, t_ray ray);
extern t_vector					intersection_cylinder(void *obj, t_ray ray);

extern t_vector					normal_error(void *obj, t_vector point);
extern t_vector					normal_na(void *obj, t_vector point);
extern t_vector					normal_sphere(void *obj, t_vector point);
extern t_vector					normal_plane(void *obj, t_vector point);
extern t_vector					normal_cylinder(void *obj, t_vector point);

typedef void					(*t_falloc)(t_alloc *_alloc);
typedef void					(*t_fmove)(void *obj,
									double world_to_cam[4][4]);
typedef t_vector				(*t_fintersection)(void *obj, t_ray ray);
typedef t_vector				(*t_fnormal)(void *obj, t_vector point);

extern const t_falloc			g_falloc[CONFIG_MAX_TYPE];
extern const t_fmove			g_fmove[CONFIG_MAX_TYPE];
extern const t_fintersection	g_fintersection[CONFIG_MAX_TYPE];
extern const t_fnormal			g_fnormal[CONFIG_MAX_TYPE];

#endif
