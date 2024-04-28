/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:02:06 by mchemcha          #+#    #+#             */
/*   Updated: 2024/04/28 17:46:46 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n
		&& ((unsigned char)s1[i] != '\0' || (unsigned char)s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		s = s + 1;
		i++;
	}
	return (s);
}

static int	ft_sign(char *str, int sign, int i)
{
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	return (sign);
}

float	ft_atof(char *str)
{
	size_t	i;
	float	sign;
	float	result;
	float	a;
	float	pow;

	result = 0;
	sign = 1;
	i = 0;
	a = 0;
	while (str[i++] == 32)
		i++;
	sign = ft_sign(str, sign, i);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
		result = (result * 10) + str[i++] - 48;
	if (str[i] == '.')
		i++;
	pow = 1;
	while (str[i])
	{
		pow /= 10;
		a = a + (str[i++] - 48) * pow;
	}
	return ((result + a) * sign);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
