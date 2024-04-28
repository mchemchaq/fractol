/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:58:18 by mchemcha          #+#    #+#             */
/*   Updated: 2024/04/28 17:32:29 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '-' || c[i] == '+')
			i++;
		while (c[i] >= '0' && c[i] <= '9')
			i++;
		if (c[i] == '.')
			i++;
		while (c[i] >= '0' && c[i] <= '9')
			i++;
		if (c[i] == '\0')
			break ;
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	img;

	if (ac == 2 && ft_strlen(av[1]) == 10 \
		&& !(ft_strncmp(av[1], "mandelbrot", 10)))
	{
		img.type = 0;
		ft_fractol(img);
		return (0);
	}
	else if (ac == 4 && ft_strlen(av[1]) == 5 \
			&& !(ft_strncmp(av[1], "julia", 5)))
	{
		if (!(ft_isdigit(av[2])) || !(ft_isdigit(av[3])))
			return (ft_putstr_fd("Envalid argumment", 2), 1);
		img.type = 1;
		img.z0_real = ft_atof(av[2]);
		img.z0_im = ft_atof(av[3]);
		ft_fractol(img);
		return (0);
	}
	else
		return (ft_putstr_fd("Envalid argumment", 2), 1);
}
