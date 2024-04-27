/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:58:18 by mchemcha          #+#    #+#             */
/*   Updated: 2024/04/27 18:39:42 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int	ft_isdigit(char *c)
{
    int i = 0;
    while (c[i])
    {
        if(!(c[i] >= '0' && c[i] <= '9'))
        {
            puts("lllll\n");   
            return(0);
        }
        while(c[i] >= '0' && c[i] <= '9')
            i++;
        if(c[i] == '.')
            i++;
        while(c[i] >= '0' && c[i] <= '9')
            i++;
    }
	return (1);
}

int main(int ac , char **av)
{
    t_data img;
    (void)av;
    if(ac == 2 && ft_strlen(av[1]) == 10 && !(ft_strncmp(av[1], "mandelbrot", 10)))
    {
        img.type = 0;
        ft_fractol(img);
        return(0);
    }
    else if(ac == 4 && ft_strlen(av[1]) == 5 && !(ft_strncmp(av[1], "julia", 5)))
    {
        if(!(ft_isdigit(av[2])) || !(ft_isdigit(av[3])))
        {
            puts("ppp\n");   
            return(ft_putstr_fd("error", 2), 1);
        }
        img.type = 1;
        img.z0_real = ft_atof(av[2]);
        img.z0_im = ft_atof(av[3]); 
        ft_fractol(img);
        return(0);
    }
    else
        return(ft_putstr_fd("error", 2), 1);
}
