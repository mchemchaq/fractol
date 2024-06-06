/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:35:01 by mchemcha          #+#    #+#             */
/*   Updated: 2024/06/02 17:55:57 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_data img, int x, int y)
{
	double	z_i;
	double	z_r;
	int		i;
	double	tmp_r;

	z_i = 0;
	z_r = 0;
	i = 0;
	img.z0_real = ((-2.0 + x * (4.0 / 800)) * img.zoom) + img.ofset_x;
	img.z0_im = (-(-2.0 + y * (4.0 / 800)) * img.zoom) + img.ofset_y;
	while (i < 150 && z_i * z_i + z_r * z_r <= 4.0)
	{
		tmp_r = z_r * z_r - z_i * z_i + img.z0_real;
		z_i = 2 * z_i * z_r + img.z0_im;
		z_r = tmp_r;
		i++;
	}
	return (i);
}

int	ft_julia(t_data img, int x, int y)
{
	double	z_i;
	double	z_r;
	int		i;
	double	tmp_r;

	i = 0;
	z_r = ((-2.0 + x * (4.0 / 800)) * img.zoom) + img.ofset_x;
	z_i = (-(-2.0 + y * (4.0 / 800)) * img.zoom) + img.ofset_y;
	while (i < 150 && z_i * z_i + z_r * z_r <= 4.0)
	{
		tmp_r = z_r * z_r - z_i * z_i + img.z0_real;
		z_i = 2 * z_i * z_r + img.z0_im;
		z_r = tmp_r;
		i++;
	}
	return (i);
}

int	ft_julia_mandel(t_data *img, int x, int y)
{
	int	fractol;

	fractol = 0;
	if (img->type == 0)
		fractol = ft_mandelbrot(*img, x, y);
	else if (img->type == 1)
		fractol = ft_julia(*img, x, y);
	return (fractol);
}

int	ft_clore(int iter, int fr)
{
	int	t;
	int	green;
	int	red;
	int	blue;

	(void)fr;
	t = (iter * 0) % 256;
	green = (iter * 3) % 256;
	red = (iter * 20) % 256;
	blue = (iter * 5) % 256;
	return ((t << 24) + (red << 16) + (green << 8) + (blue));
}
