/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:15:33 by mchemcha          #+#    #+#             */
/*   Updated: 2024/05/22 21:35:26 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	info_img(t_data *img)
{
	img->zoom = 1.0;
	img->ofset_x = 0.0;
	img->ofset_y = 0.0;
}

int	key_hand(int keysym, t_data *img)
{
	if (keysym == 53)
	{
		mlx_clear_window(img->mlx, img->mlx_win);
		exit(0);
	}
	if (keysym == 123)
		img->ofset_x -= 0.20 * img->zoom;
	if (keysym == 124)
		img->ofset_x += 0.20 * img->zoom;
	if (keysym == 126)
		img->ofset_y -= 0.20 * img->zoom;
	if (keysym == 125)
		img->ofset_y += 0.20 * img->zoom;
	draw_fractol(*img);
	return (0);
}

int	key_hand1(t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	exit(0);
}

int	mouse_handler(int button, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (button == 4)
		img->zoom *= 0.95;
	else if (button == 5)
		img->zoom *= 1.05;
	else
		return (0);
	draw_fractol(*img);
	return (0);
}

void	ft_fractol(t_data img)
{
	info_img(&img);
	my_mlx_win(&img);
	draw_fractol(img);
	mlx_hook(img.mlx_win, 02, 1L << 0, key_hand, &img);
	mlx_mouse_hook(img.mlx_win, mouse_handler, &img);
	mlx_hook(img.mlx_win, 17, 1L << 17, key_hand1, &img);
	mlx_loop(img.mlx);
}
