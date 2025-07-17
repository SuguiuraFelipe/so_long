# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 21:20:56 by fsuguiur          #+#    #+#              #
#    Updated: 2025/07/17 18:01:20 by fsuguiur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# === Nome do executável ===
NAME     = so_long

# === Fontes ===
SRC      = src/main.c \
           src/read_map.c \
           src/check_args.c \
           src/map_utils.c \
           src/validation.c \
           src/validation_elements.c \
           src/flood_fill_utils.c \
           src/flood_fill.c \
           src/render.c \
           src/game.c \
           src/input.c \
           src/cleanup.c \
           get_next_line/get_next_line.c \
           get_next_line/get_next_line_utils.c

# === Diretórios ===
OBJDIR   = obj/
MLX_DIR  = minilibx-linux

OBJ      = $(SRC:%.c=$(OBJDIR)%.o)

# === Compilador e flags ===
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -I include -I $(MLX_DIR)

# === Flags para linkar MiniLibX no Linux (sem Xpm) ===
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# === Regras principais ===

all: $(NAME)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

$(OBJDIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# === Limpeza ===

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re