/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:05:33 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/06 14:38:35 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	miniRT(void)
{
	t_camera	cam;
	t_object	sphere;
	t_lighting	ambient_lighting;
	t_light	light;
	t_data	img;
	t_vars	vars;

	img.width = 1000;
	img.height = 1000;
	img.img = mlx_new_image(vars.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.endian);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd("Wrong usage.\n", 2), 1);
	(void)argv;
	/*check_file(argv[1]);*/
	miniRT();
}
