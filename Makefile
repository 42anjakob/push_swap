NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	push_swap.c \
			utils.c \
			sort.c

LIBFT	=	libft/libft.a

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/ > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make -C libft/ clean > /dev/null 2>&1
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean > /dev/null 2>&1
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re