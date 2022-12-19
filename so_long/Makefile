NAME = so_long

SRC = so_long.c utils/exit.c utils/renderer.c utils/algo_check.c utils/gameEvent.c utils/map_checker.c utils/map_save.c utils/get_next_line.c utils/get_next_line_utils.c

# OBJ = so_long.o utils/algo_check.o utils/gameEvent.o utils/map_checker.o utils/map_save.o utils/get_next_line.o utils/get_next_line_utils.o
OBJ = $(SRC:%.c=%.o)
LIBFT = libft/libft.a

HEADER = includes/so_long.h
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

# -fsanitize=address -g
# -Lmlx
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I $(HEADER) $(LIBFT)
# $(OBJ): $(SRC)
# 	$(CC) $(CFLAGS) -c $< -o $@
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I $(HEADER) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -L/usr/lib -Imlx_linux -lm -lz -o $(NAME)
# 	# cc -Wall -Werror -Wextra -I $(HEADER) -c $(SRC) 
# 	$(MAKE) do_configure -C ./minilibx-linux
# 	ar rc $(NAME) $(OBJ)
# 	ranlib $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(NAME): $(OBJ)
# 	cc -Wall -Werror -Wextra -I $(HEADER) -c $(SRC) 
# 	$(MAKE) do_configure -C ./minilibx-linux
# 	ar rc $(NAME) $(OBJ)
# 	ranlib $(NAME)


clean:
	/bin/rm -rf $(OBJ)

fclean:
	/bin/rm -rf $(NAME) $(OBJ)

re: fclean all
