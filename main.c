/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaffal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:05:33 by lchaffal          #+#    #+#             */
/*   Updated: 2025/08/13 12:48:19 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	compute_image(t_data *img)
{
	int	i;
	int	j;
	unsigned int	color;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			color = 124;
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

static void	miniRT(void)
{
	t_camera	cam;
	t_object	sphere;
	/*t_lighting	ambient_lighting;*/
	/*t_light	light;*/
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Pouet");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.endian);
	compute_image(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, escape_pressed, &vars);
	mlx_hook(vars.win, 17, 1L << 3, close_mouse, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd("Wrong usage.\n", 2), 1);
	(void)argv;
	/*check_file(argv[1]);*/
	miniRT();
}
