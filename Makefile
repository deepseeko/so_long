NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MLX_FLAG_WITH_OBJ = -Wall -Wextra -Werror
MLX_FLAG =  -lmlx -lXext -lX11

SRCS = game/main.c \
    game/checker.c \
    game/clear.c \
    game/init_data.c \
    game/put_enemy.c \
    game/load_textures.c \
    game/check_wall.c \
    game/check_char.c \
    game/render_player.c \
    game/render_enemy.c \
    game/get_index.c \
    game/get_map.c \
    game/ft_error.c \
    game/init_win.c \
    game/stats.c \
    game/render.c \
    game/render_coin.c \
    game/delay_handler.c \
    game/check_flood_fill.c \
    get_next_line/get_next_line.c \
    get_next_line/get_next_line_utils.c \


OBJS = $(SRCS:.c=.o)

LIBFT_PATH = src
LIBFT = $(LIBFT_PATH)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAG) -o $(NAME)

%.o: %.c includes/solong.h
	$(CC) $(CFLAGS) $(MLX_FLAG_WITH_OBJ) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)
