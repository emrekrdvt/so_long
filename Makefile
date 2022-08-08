NAME =  so_long

LIBFT = libft/libft.a

SRC = src/define.c src/error.c  src/map.c  src/move.c  src/operations.c  src/utils.c src/main.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./libft -I./printf -I./mlx 
OFLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit -Llibft -lft -Lmlx -lmlx

all: mlx libft $(NAME)

libft:
	make -C libft
mlx:
	make -C mlx

$(NAME): $(OBJ)
	gcc $(OFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
re: fclean all

.PHONY:all clean fclean re mlx libft
