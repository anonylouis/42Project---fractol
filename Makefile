CC = gcc

FLAGS = -Wall -Wextra -Werror # -g3 -fsanitize=address

FLAGS_MINILIBX = -L/user/include/../lib -lXext -lX11 -lm 
MINILIBX= minilibx/libmlx_Linux.a

NAME = fractol

SOURCES = atod.c argument.c burningShip.c color.c complex.c graph.c julia.c key.c main.c mandelbrot.c mouse.c movegraph.c print.c utils.c xpm.c
SRCS = $(addprefix ./srcs/, $(SOURCES))

OBJS = ${SRCS:.c=.o}

HEADER = ./includes

all : $(NAME)

$(NAME) :	makeminilibx $(OBJS)
			gcc $(FLAGS) -o $(NAME) $(OBJS) $(MINILIBX) $(FLAGS_MINILIBX)

clean : 
		rm -f $(OBJS)

fclean : clean 
		rm -f $(NAME)
		$(MAKE) -C minilibx/ clean

re :	fclean all

bonus : all

makeminilibx : 
		$(MAKE) -C minilibx/ all

./srcs/%.o :	./srcs/%.c
				$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $< $(MINILIBX) $(FLAGS_MINILIBX) 

.PHONY : all re clean fclean makeminilibx
