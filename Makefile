NAME			=	push_swap

CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	push_swap.c \
					utils.c \
					sort.c \
					less_then_six.c \
					init.c

LIBFT_URL		=	https://github.com/42anjakob/libft.git
LIBFT_DIR		=	libft
LIBFT_ARCHIVE	=	libft/libft.a

OBJS_DIR		=	objects
OBJS			=	${SRCS:%.c=$(OBJS_DIR)/%.o}

all: $(NAME)

$(NAME): $(LIBFT_INSTALL) $(OBJS)
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARCHIVE) -o $(NAME)

$(LIBFT_INSTALL):
	@test -d $(LIBFT_DIR) || git clone $(LIBFT_URL)

$(OBJS_DIR)/%.o: %.c
	@test -d $(OBJS_DIR) || mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
