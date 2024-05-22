/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:04:04 by mchemcha          #+#    #+#             */
/*   Updated: 2024/05/21 15:42:43 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_win(t_data *img)
{
	img->mlx = mlx_init();
	if (!(img->mlx))
		exit(0);
	if (!(img->type))
		img->mlx_win = mlx_new_window(img->mlx, 800, 800, "mandelbrot");
	if (img->type)
		img->mlx_win = mlx_new_window(img->mlx, 800, 800, "julia");
	if (!(img->mlx_win))
		exit(0);
	img->img = mlx_new_image(img->mlx, 800, 800);
	if (!(img->img))
	{
		mlx_destroy_image(img->mlx, img->img);
		exit(0);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel \
								, &img->line_length, &img->endian);
	if (!(img->addr))
	{
		mlx_destroy_image(img->mlx, img->img);
		exit(0);
	}
}
