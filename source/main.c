/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:04:45 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 14:56:17 by lchaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_alloc	_alloc;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong usage.\nError\n", 2);
		return (1);
	}
	filename(argv[1]);
	ft_bzero(&_alloc, sizeof(_alloc));
	alloc(&_alloc);
	return (0);
}

int	event_key(int key, void *mlx)
{
	if (key == XK_Escape)
		mlx_loop_end(mlx);
	return (0);
}

int	event_destroy(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

void	free_window(void *mlx, t_win_list *win, t_img *img, char flag)
{
	if (img != 0)
		mlx_destroy_image(mlx, img);
	if (win != 0)
		mlx_destroy_window(mlx, win);
	if (mlx != 0)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
	if (flag != 0)
	{
		error(ERROR_BAD_WINDOW);
	}
}

void	malloc_window(t_alloc *objs_list)
{
	void			*mlx;
	t_win_list		*win;
	t_img			*img;

	mlx = 0;
	win = 0;
	img = 0;
	mlx = mlx_init();
	if (mlx == 0)
		free_window(mlx, win, img, 1);
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "MiniRT L&L");
	if (win == 0)
		free_window(mlx, win, img, 1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (img == 0)
		free_window(mlx, win, img, 1);
	move_everything(objs_list, objs_list->camera);
	compute_image(img, objs_list);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_hook(win, KeyPress, KeyPressMask, event_key, mlx);
	mlx_hook(win, DestroyNotify, 0, event_destroy, mlx);
	mlx_loop(mlx);
	free_window(mlx, win, img, 0);
}
