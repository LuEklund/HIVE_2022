NAME = push_swap

SRC = utils/op_helper.c utils/a_sort.c utils/finder.c utils/put_in_b.c utils/start_sort.c utils/freer.c utils/integer_checker.c utils/error.c utils/operators.c push_swap.c

OBJ = $(SRC:%.c=%.o)

HEADER = includes/push_swap.h
CFLAGS = -Wall -Wextra -Werror -g

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
