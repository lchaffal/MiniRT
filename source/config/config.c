/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:55:27 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 08:55:28 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "config_obj.h"
#include "config_function.h"

const unsigned char			g_dummy_id = 0;
const unsigned long long	g_dummy_name = 0;
const unsigned char			g_dummy_rule[] = {
	0};

const unsigned char			g_ambient_id = 1;
const unsigned long long	g_ambient_name = ('A');

const unsigned char			g_camera_id = 2;
const unsigned long long	g_camera_name = ('C');

const unsigned char			g_light_id = 3;
const unsigned long long	g_light_name = ('L');

const unsigned char			g_plane_id = 4;
const unsigned long long	g_plane_name = ('p') | ('l' << 8);

const unsigned char			g_sphere_id = 5;
const unsigned long long	g_sphere_name = ('s') | ('p' << 8);

const unsigned char			g_cylinder_id = 6;
const unsigned long long	g_cylinder_name = ('c') | ('y' << 8);

const unsigned char			*g_objs_id[CONFIG_MAX_TYPE] = {
	&g_dummy_id,
	&g_ambient_id,
	&g_camera_id,
	&g_light_id,
	&g_plane_id,
	&g_sphere_id,
	&g_cylinder_id
};

const unsigned long long	*g_objs_name[CONFIG_MAX_TYPE] = {
	&g_dummy_name,
	&g_ambient_name,
	&g_camera_name,
	&g_light_name,
	&g_plane_name,
	&g_sphere_name,
	&g_cylinder_name
};

const t_falloc				g_falloc[CONFIG_MAX_TYPE] = {
	alloc_error,
	alloc_na_ambient,
	alloc_na_camera,
	alloc_light,
	alloc_plane,
	alloc_sphere,
	alloc_cylinder
};

const t_fmove				g_fmove[CONFIG_MAX_TYPE] = {
	move_error,
	move_na,
	move_na,
	move_light,
	move_plane,
	move_sphere,
	move_cylinder
};

const t_fintersection		g_fintersection[CONFIG_MAX_TYPE] = {
	intersection_error,
	intersection_na,
	intersection_na,
	intersection_na,
	intersection_plane,
	intersection_sphere,
	intersection_cylinder
};

const t_fnormal				g_fnormal[CONFIG_MAX_TYPE] = {
	normal_error,
	normal_na,
	normal_na,
	normal_na,
	normal_plane,
	normal_sphere,
	normal_cylinder
};
