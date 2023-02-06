NAME = philo

SRC = utils/thread_check.c utils/processes.c utils/start_eat.c utils/freer.c philo.c

OBJ = $(SRC:%.c=%.o)

HEADER = includes/philo.h

CFLAGS = -pthread -g -Wall -Wextra -Werror 

# REMOVE "-pthread" and "-g" !?!!???!?!??!? AND REMOVE -g -fsanitize=address FROM RULE $(NAME)



.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -I $(HEADER)
clean:
	/bin/rm -rf $(OBJ) $(OBJS)

fclean:
	/bin/rm -rf $(NAME) $(OBJ)

re: fclean all