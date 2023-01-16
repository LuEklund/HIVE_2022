NAMEC = client
NAMES = server

SRCC = client.c
SRCS = server.c

OBJC = $(SRCC:%.c=%.o)
OBJS = $(SRCS:%.c=%.o)

HEADERC = includes/client.h
HEADERS = includes/server.h
CFLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

all: $(NAMEC) $(NAMES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAMEC): $(OBJC)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf
	$(CC) $(OBJC) -o $(NAMEC) -I $(HEADERC) -Llibft -lft -Lft_printf -lftprintf
$(NAMES): $(OBJS)
	$(CC) $(OBJS) -o $(NAMES) -I $(HEADERS) -Llibft -lft -Lft_printf -lftprintf
clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	/bin/rm -rf $(OBJC) $(OBJS)

fclean:
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	/bin/rm -rf $(NAMEC) $(OBJC) $(NAMES) $(OBJS)

re: fclean all
