NAME = libftprintf.a

SRC = ft_printf.c utils_printf.c

SRCO = ft_printf.o utils_printf.o

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(SRCO)
	cc -Wall -Werror -Wextra -I $(HEADER) -c $(SRC)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(SRCO)

fclean:
	/bin/rm -rf $(NAME) $(SRCO)

re: fclean all
