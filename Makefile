# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 19:27:00 by fsuguiur          #+#    #+#              #
#    Updated: 2025/07/03 19:27:02 by fsuguiur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = so_long

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
        	src/cleanup.c\
            get_next_line/get_next_line.c \
            get_next_line/get_next_line_utils.c

OBJ      = objs/main.o \
            objs/read_map.o \
            objs/check_args.o \
            objs/map_utils.o \
            objs/validation.o \
            objs/validation_elements.o \
			objs/flood_fill_utils.o \
			objs/flood_fill.o \
			objs/render.o \
			objs/game.o \
			objs/input.o \
		    objs/cleanup.o\
            objs/get_next_line.o \
            objs/get_next_line_utils.o

CC       = cc
CFLAGS = -Wall -Wextra -Werror -I include -I mlx -I/opt/homebrew/include

ifeq ($(shell uname -s),Darwin)
	MLX_COMPILE = echo "\033[1;33mCompiling mlx...\033[0m"; tar -xf minilibx-linux.tgz; make -C minilibx-linux; cp minilibx-linux/libmlx_Darwin.a mlx/libmlx.a; rm -rf minilibx-linux
    MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit
else
	MLX_COMPILE = echo "\033[1;33mCompiling mlx...\033[0m"; tar -xf minilibx-linux.tgz; make -C minilibx-linux; cp minilibx-linux/libmlx.a mlx/; rm -rf minilibx-linux
    MLX_FLAGS = -Lmlx -lmlx -lXext -lX11
endif

all: $(NAME)

$(NAME): mlx/libmlx.a $(OBJDIR) $(OBJS)
	@cc $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

mlx/libmlx.a:
	mkdir -p mlx
	@$(MLX_COMPILE)

$(OBJDIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME) mlx/libmlx.a minilibx-linux

re: fclean all

.PHONY: all clean fclean re