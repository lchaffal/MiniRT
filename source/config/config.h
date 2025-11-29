/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:55:33 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 15:51:48 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

// MiniRT Configuration
# define CONFIG_MAX_OBJ		100000
# define CONFIG_MAX_TYPE	7
# define WIDTH 1500
# define HEIGHT 1000
# define OFFSET 0.00001
# define KS 0.5
# define ALPHA 250

// If you increase more than 65535,
// you need to replace 'short' with 'int' or 'long' in config_typedef.h
# define CONFIG_MAX_LINESIZE 10000

#endif
