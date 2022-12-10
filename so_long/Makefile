NAME = so_long.a

<<<<<<< HEAD
SRC = so_long.c utils/gameEvent.c utils/map_checker.c utils/map_save.c utils/get_next_line.c utils/get_next_line_utils.c

SRCO = so_long.o utils/gameEvent.o utils/map_checker.o utils/map_save.o utils/get_next_line.o utils/get_next_line_utils.o
=======
SRC = so_long.c utils/map.c utils/get_next_line.c utils/get_next_line_utils.c

SRCO = so_long.o utils/map.o utils/get_next_line.o utils/get_next_line_utils.o
>>>>>>> 969cf1c06c8d637dc0c027ddb5417057a35125bd

HEADER = includes/so_long.h

all: $(NAME)

<<<<<<< HEAD
# -fsanitize=address -g
=======

>>>>>>> 969cf1c06c8d637dc0c027ddb5417057a35125bd
# -Lmlx
%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(SRCO)
	$(CC) $(SRCO) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I $(HEADER)
	
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I $(HEADER) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(SRCO)
# 	$(CC) $(SRCO) -L/usr/lib -Imlx_linux -lm -lz -o $(NAME)
# 	# cc -Wall -Werror -Wextra -I $(HEADER) -c $(SRC) 
# 	$(MAKE) do_configure -C ./minilibx-linux
# 	ar rc $(NAME) $(SRCO)
# 	ranlib $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(NAME): $(SRCO)
# 	cc -Wall -Werror -Wextra -I $(HEADER) -c $(SRC) 
# 	$(MAKE) do_configure -C ./minilibx-linux
# 	ar rc $(NAME) $(SRCO)
# 	ranlib $(NAME)

clean:
	/bin/rm -rf $(SRCO)

fclean:
	/bin/rm -rf $(NAME) $(SRCO)

re: fclean all
