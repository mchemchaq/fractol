/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:29:11 by mchemcha          #+#    #+#             */
/*   Updated: 2024/06/02 17:55:57 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <unistd.h> 
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	double	ofset_x;
	double	ofset_y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		type;
	double	zoom;
	double	z0_im;
	double	z0_real;
	void	*img;
	void	*mlx_win;
	void	*mlx;
	char	*addr;
}	t_data;

double	ft_atof(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_fractol(t_data img);
int		ft_error(char *str);
void	draw_fractol(t_data img);
int		ft_clore(int iter, int fr);
void	my_mlx_win(t_data *img);
int		ft_julia(t_data img, int x, int y);
int		ft_mandelbrot(t_data img, int x, int y);
int		ft_julia_mandel(t_data *img, int x, int y);
int		mouse_handler(int button, int x, int y, t_data *img);
int		key_hand1(t_data *img);
int		key_hand(int keysym, t_data *img);
void	ft_putstr_fd(char *str, int fd);

#endif