NAME = libget_next_line.a

SRC = get_next_line.c get_next_line_utils.c main.c

SRCO = get_next_line.o get_next_line_utils.o main.o

HEADER = get_next_line.h

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(SRCO)
	@cc -Wall -Werror -Wextra -D BUFFER_SIZE=1 -I $(HEADER) -c $(SRC)
	@ar rc $(NAME) $(SRCO)
	@gcc main.c -L. -lget_next_line -g -fsanitize=address
	@ranlib $(NAME)
	@./a.out main.c
	@/bin/rm -f $(SRCO) $(NAME) 
clean:
	/bin/rm -rf $(SRCO)

fclean:
	/bin/rm -rf $(NAME) $(SRCO)

re: fclean all
