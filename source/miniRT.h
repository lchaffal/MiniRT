/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:06:06 by lchaffal          #+#    #+#             */
/*   Updated: 2025/09/23 15:59:54 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// standard
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

// X11 define
# include <X11/X.h>
# include <X11/Xutil.h>

// minilibx define
# include <mlx.h>
# include <mlx_int.h>

// me
# include "config/config.h"
# include "config/config_typedef.h"
# include "config/config_obj.h"

// error sigl-line
# define ERROR_BAD_ALLOC "- You try to alloc a none alocable type\n"
# define ERROR_BAD_NORMAL "- You try to normal a none normalable type\n"
# define ERROR_BAD_MOVE "- You try to move a none movalable type\n"
# define ERROR_BAD_INTERSECTION "- You try to intersect a \
none intersectable type\n"
# define ERROR_BAD_NUMBER "- Your config has too much objects\n"
# define ERROR_MISSING_MDTR "- Ambient lightning or camera is missing\n"

# define ERROR_BAD_TYPE "- Your configuration is trying to set an unknown \
type\n"
# define ERROR_BAD_VALUE "- Your configuration is trying to set an unknown \
value\n"

# define ERROR_BAD_FILE "- Error when I try to open your configuration file\n"

# define ERROR_BAD_FILENAME "- Error: bad file name\n"
# define ERROR_BAD_FILEEXT "- Error: bad file extension\n"

# define ERROR_BAD_WINDOW "- Error when I try to open the window\n"

// error multi-line
# define ERROR_NORM "- Your configuration contains a non-normalized vector, \
but the object needs to be normalized"
# define ERROR_TOO_MANY "- Your configuration is trying to add more \
than one "

t_vector		normal(void *obj, t_vector point);
void			move_everything(t_alloc *objs_list, double world_to_cam[4][4]);

void			move(void *obj, double world_to_cam[4][4]);
t_vector		intersection(void *obj, t_ray ray);
void			*intersection_everything(t_ray ray,
					t_vector *intersection_point, t_alloc *objs_list);

void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

double			ft_atod(const unsigned char *str,
					unsigned int number, unsigned char *_error);

char			*filename(char *_path);
void			alloc(t_alloc *_alloc);

unsigned char	file_read_type(int fd, t_alloc *alloc);
unsigned char	file_read_value(int fd, t_alloc *alloc);

void			error(char *str);
void			malloc_window(t_alloc *objs_list);

// ft
int				ft_isdigit(int c);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
int				ft_isalpha(int c);
int				ft_isspace(char c);
int				ft_capalpha(int c);

void			obj_limit(t_alloc *alloc, unsigned char id, char *label,
					unsigned char *_error);
void			norm_limit(t_vector *orientation, char *label,
					unsigned char *_error);
t_vector		create_vector(double x, double y, double z, double w);
double			norm_of(t_vector u);
t_vector		vector_product(t_vector u, t_vector v);
t_vector		linear_combination(t_vector u, t_vector v,
					double k1, double k2);
t_vector		double_times_vector(double f, t_vector u);
double			scalar_product(t_vector u, t_vector v);
void			normalize(t_vector *u);
t_vector		vector_times_mat(t_vector u, double m[4][4]);
t_vector		find_coordinates(int x, int y, double fov);
void			find_world_to_cam(t_vector *position, t_vector *orientation,
					double world_to_cam[4][4]);
int				create_color(t_vector color);
void			loading(int i);

t_vector		get_object_color(void *obj);
t_vector		get_normal(t_vector point, void *obj);

void			compute_image(t_img *img, t_alloc *objs_list);

// INTERSECTION
t_vector		select_sphere_answer(double abc[3], double delta, t_ray ray);

t_vector		select_cylinder_answer(double abc[3], double delta,
					t_ray ray, t_obj_cylinder *cyl);
t_vector		try_cylinder_answers(double t1, double t2,
					t_ray ray, t_obj_cylinder *cyl);

void			compute_cylinder_a(double *a, t_obj_cylinder *cyl,
					t_ray ray, t_vector minus_a_squared);
void			compute_cylinder_b(double *b, t_obj_cylinder *cyl,
					t_ray ray, t_vector minus_a_squared);
void			compute_cylinder_c(double *c, t_obj_cylinder *cyl,
					t_ray ray, t_vector minus_a_squared);

void			parsing_ambient(t_alloc *alloc,
					unsigned char *buffer_data, unsigned char *_error);
void			parsing_camera(t_alloc *alloc,
					unsigned char *buffer_data, unsigned char *_error);
void			parsing_light(t_alloc *alloc,
					unsigned char *buffer_data, unsigned char *_error);
void			parsing_plane(t_alloc *alloc,
					unsigned char *buffer_data, unsigned char *_error);
void			parsing_sphere(t_alloc *alloc,
					unsigned char *buffer_data, unsigned char *_error);
void			parsing_cylinder(t_alloc *alloc,
					unsigned char *buffer_data, unsigned char *_error);

void			try_get_type(t_alloc *_alloc,
					unsigned char *buffer_data, unsigned short *buffer_size,
					unsigned char *_error);

void			try_get_value(t_alloc *_alloc,
					unsigned char *buffer_data, unsigned short *buffer_size,
					unsigned char *_error);

#endif
