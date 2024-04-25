/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:15:33 by mchemcha          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:12 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


static void info_img(t_data *img)
{
    img->zoom = 1.0;
}
void my_mlx_win(t_data *img)
{

	img->mlx = mlx_init();
    if(!(img->mlx))
        exit(0);
    if(!(img->type))
	    img->mlx_win = mlx_new_window(img->mlx, 800, 800, "mandelbrot");
    if(img->type)
	    img->mlx_win = mlx_new_window(img->mlx, 800, 800, "julia");
    if(!(img->mlx_win))
        exit(0);
	img->img = mlx_new_image(img->mlx, 800, 800);
    if(!(img->img))
    {
        mlx_destroy_image(img->mlx,img->img);
        exit(0);
    }
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    if(!(img->addr))
    {
        mlx_destroy_image(img->mlx,img->img);
        exit(0);
    }
}
int key_hand(int keysym)
{
    if(keysym ==  53)
        exit(0);
    return (0);
}

int mouse_handler(int button, int x, int y, t_data *img)
{
    (void)x;
    (void)y;
    if(button == 4)
        img->zoom *= 0.95;
    else if(button == 5)
        img->zoom *= 1.05;
    else
        return(0);
    draw_fractol(*img);
    return(0);
}

void ft_fractol(t_data img)
{
    info_img(&img);
    my_mlx_win(&img);
    draw_fractol(img);
    mlx_hook(img.mlx_win, 02, 1L<<0, key_hand, &img);
    mlx_mouse_hook(img.mlx_win, mouse_handler, &img);
    // mlx_hook(img.mlx_win, 17, 1L<<0 ,key_hand, &img);
    mlx_loop(img.mlx);
}