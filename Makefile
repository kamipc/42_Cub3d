#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 19:47:17 by cpinho-c          #+#    #+#              #
#    Updated: 2026/07/02 18:00:03 by sade-ara         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = minilibx-linux

INCLUDES = -Iheaders -I$(MLX_DIR)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm


SRC = \
	main_test.c \
	inits/init_cub3d.c \
	inits/init_image.c \
	inits/init_map.c \
	inits/init_player.c \
	inits/init_ray.c \
	inits/init_textures.c \
	inits/init_window.c \
	utils/error.c \
	utils/get_info_utils.c \
	utils/validate_map_utils.c \
	free/free_array.c \
	free/free_cub3d.c \
	free/free_map.c \
	free/free_textures.c \
	execution/player/move.c \
	execution/player/rotate.c \
	execution/hooks/close_win.c \
	execution/hooks/key_press.c \
	execution/hooks/key_release.c \
	execution/raycast/raycast.c \
	execution/render/draw_utils.c \
	execution/render/draw_wall.c \
	execution/render/draw.c \
	execution/render/gets.c \
	execution/render/load_textures.c \
	execution/render/render.c \
	execution/render/sets.c \
	parsing/get_info.c \
	parsing/save_color.c \
	parsing/validate_file.c \
	parsing/validate_map.c \
	parsing/validate_textures.c \
	parsing/validate.c 

OBJ = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR) -O3 -std=gnu99
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MLX_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re