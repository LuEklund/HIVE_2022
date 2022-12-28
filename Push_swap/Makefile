NAME = push_swap

SRC = utils/integer_checker.c push_swap.c

OBJ = $(SRC:%.c=%.o)

HEADER = includes/push_swap.h
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf
	$(CC) $(OBJ) -o $(NAME) -I $(HEADER) -Llibft -lft -Lft_printf -lftprintf
clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	/bin/rm -rf $(OBJ)

fclean:
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	/bin/rm -rf $(NAME) $(OBJ)

re: fclean all
