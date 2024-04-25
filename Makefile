SRCS  = mandelbrot_julia.c fractol.c utils.c ft_error.c draw_fractol.c finel.c

NAME = fractol

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -O3

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(FLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJS) 

fclean : clean
	$(RM) $(NAME) 

re : fclean all

.PHONY : clean