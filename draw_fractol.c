/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:27:04 by mchemcha          #+#    #+#             */
/*   Updated: 2024/05/22 14:06:10 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_data img)
{
	int	pixel;
	int	*addr;
	int	x;
	int	y;
	int	iter;

	y = -1;
	iter = 0;
	addr = (int *)img.addr;
	while (++y < 800)
	{
		x = -1;
		while (++x < 800)
		{
			iter = ft_julia_mandel(&img, x, y);
			pixel = (y * 800) + x;
			if (iter < 150)
				addr[pixel] = ft_clore(iter, 0);
			else
				addr[pixel] = 0;
		}
	}
	mlx_clear_window(img.mlx, img.mlx_win);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
}
