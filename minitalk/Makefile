NAMEC = client
NAMES = server

NAMEC_BONUS = client_bonus
NAMES_BONUS = server_bonus

SRCC = client.c
SRCS = server.c

SRCC_BONUS = client_bonus.c
SRCS_BONUS = server_bonus.c

OBJC = $(SRCC:%.c=%.o)
OBJS = $(SRCS:%.c=%.o)

OBJC_BONUS = $(SRCC_BONUS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

HEADERC = includes/client.h
HEADERS = includes/server.h

HEADERC_BONUS = includes/client_bonus.h
HEADERS_BONUS = includes/server_bonus.h

CFLAGS = -Wall -Wextra -Werror

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
	/bin/rm -rf $(OBJC) $(OBJS) $(OBJC_BONUS) $(OBJS_BONUS) $(NAMEC_BONUS) $(NAMES_BONUS)

fclean:
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	/bin/rm -rf $(NAMEC) $(OBJC) $(NAMES) $(OBJS) $(OBJC_BONUS) $(OBJS_BONUS) $(NAMEC_BONUS) $(NAMES_BONUS)

re: fclean all


bonus: $(NAMEC_BONUS) $(NAMES_BONUS)

$(NAMEC_BONUS): $(OBJC_BONUS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf
	$(CC) $(OBJC_BONUS) -o $(NAMEC_BONUS) -I $(HEADERC_BONUS) -Llibft -lft -Lft_printf -lftprintf
$(NAMES_BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(NAMES_BONUS) -I $(HEADERS_BONUS) -Llibft -lft -Lft_printf -lftprintf
