NAME = so_long

SRC = so_long.c utils/exit.c utils/renderer.c utils/algo_check.c utils/gameEvent.c utils/map_checker.c utils/map_save.c utils/get_next_line.c utils/get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)
LIBFT = libft/libft.a

HEADER = includes/so_long.h
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I $(HEADER) $(LIBFT)
clean:
	/bin/rm -rf $(OBJ)

fclean:
	/bin/rm -rf $(NAME) $(OBJ)

re: fclean all
