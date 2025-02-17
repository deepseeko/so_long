NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f
MLCFLAGS = -Imlx -lXext -lX11
SRCS = game/main.c \
	game/checker.c \
	game/clear.c \
	game/init_data.c \
	game/check_wall.c \
	game/check_char.c \
	game/check_flood_fill.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

LIBFT_PATH = src
LIBFT = $(LIBFT_PATH)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c includes/solong.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re

