NAME			=	push_swap

CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	push_swap.c \
					init.c \
					utils.c \
					sort.c \
					less_then_six.c

LIBFT_URL		=	https://github.com/42anjakob/libft.git
LIBFT_DIR		=	libft/
LIBFT_ARCHIVE	=	libft/libft.a

OBJS_DIR		=	objects/
OBJS			=	${SRCS:%.c=$(OBJS_DIR)/%.o}

all: libft_install $(NAME)

libft_install:
	@test -d $(LIBFT_DIR) || git clone $(LIBFT_URL)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARCHIVE) -o $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@rm -r $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@rm $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libft_install
