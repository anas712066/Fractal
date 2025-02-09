NAME = fractol

CC = cc 
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux/ -Imlx_linux -O3


SRCS = main.c \
       init.c \
       math_utils.c \
       render.c \
       string_utils.c
	   
OBJS = $(SRCS:.c=.o)

# Reglas principales
all: $(NAME) fractol.h Makefile

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./minilibx-linux/libmlx_Linux.a -Lmlx_linux -I./minilibx-linux/ -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
