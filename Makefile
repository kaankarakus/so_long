NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -Iheaders/
MLX_PATH = lib/minilibx
LIBRARY = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
MLX = libmlx.a
LIBFT_PATH = lib/libft
LIBFT	= libft.a
FT_PRINTF_PATH = lib/ft_printf
FT_PRINTF = libftprint.a
SRCS = so_long.c utils/render_map.c utils/move.c utils/map.c utils/map_check.c utils/game_check.c lib/get_next_line_utils.c lib/get_next_line.c
OBJS=$(SRCS:.c=.o)

all: $(MLX) $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_PATH) -L $(FT_PRINTF_PATH) -lft -lftprintf $(LIBRARY) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

$(FT_PRINTF):
	@make -s -C $(FT_PRINTF_PATH)

$(MLX):
	@make -s -C $(MLX_PATH) -j16 2> /dev/null

clean:
	@$(RM) $(OBJS)
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean

re: fclean all