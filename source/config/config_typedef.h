/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_typedef.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:55:50 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:55:51 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_TYPEDEF_H
# define CONFIG_TYPEDEF_H

# include "config.h"

typedef struct s_vecto
{
	double					x;
	double					y;
	double					z;
	double					w;
}	t_vector;

typedef struct s_ray
{
	t_vector				origin;
	t_vector				direction;
}	t_ray;

typedef struct s_alloc
{
	unsigned int			index;

	t_vector				ambient;
	double					camera[4][4];
	double					fov;

	unsigned char			identifier[CONFIG_MAX_OBJ];
	void					*obj[CONFIG_MAX_OBJ];
	unsigned char			number[CONFIG_MAX_OBJ];
}	t_alloc;

typedef struct s_pointed_obj {
	void		*obj;
	t_vector	point;
}	t_pointed_obj;

typedef struct s_file_obj {
	unsigned char	lock;
	unsigned char	buffer;
	unsigned char	buffer_data[CONFIG_MAX_LINESIZE];
	unsigned short	buffer_size;
	unsigned char	error;
}	t_file_obj;

#endif
