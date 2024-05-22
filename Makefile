# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 17:38:06 by mchemcha          #+#    #+#              #
#    Updated: 2024/05/21 15:44:58 by mchemcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = mandelbrot_julia.c fractol.c utils.c ft_error.c draw_fractol.c finel.c mlx.c

NAME = fractol

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -O3

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fract_ol.h
	$(CC) $(FLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJS) 

fclean : clean
	$(RM) $(NAME) 

re : fclean all

.PHONY : clean