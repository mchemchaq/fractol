/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:32:00 by mchemcha          #+#    #+#             */
/*   Updated: 2024/04/24 21:56:21 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include <unistd.h> 
# include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_complex
{
    double a; 
    double b; 
}t_complex;

typedef struct	s_data {
    float     zoom; 
    int     type;
    float   z0_im;
    float   z0_real;
	void	*img;
    void    *mlx_win;
    void    *mlx;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 100

#define Button1       1
#define Button2       2
#define Button3       3
#define Button4       4
#define Button5       5

float	ft_atof(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void ft_fractol(t_data img);
int	ft_error(char *str);
void draw_fractol(t_data img);
int ft_clore(int iter, int fr);
void my_mlx_win(t_data *img);
int ft_julia(t_data img, int x, int y);
int ft_mandelbrot(t_data img, int x, int y);
int ft_julia_mandel(t_data *img, int x, int y);
int mouse_handler(int button, int x, int y, t_data *img);
int key_hand(int keysym);
// get inf
// mmlx_win
// draw 
// loop 

#endif