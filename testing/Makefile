# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 16:29:18 by cpinho-c          #+#    #+#              #
#    Updated: 2026/07/11 22:56:54 by cpinho-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = main_test.c \
	   ../free/free_array.c \
	   ../free/free_cub3d.c \
	   ../free/free_map.c \
	   ../free/free_textures.c \
	   ../inits/init_cub3d.c \
	   ../inits/init_map.c \
	   ../inits/init_textures.c \
	   ../parsing/get_info.c \
	   ../parsing/validate_file.c \
	   ../parsing/validate_map.c \
	   ../parsing/validate_textures.c \
	   ../parsing/validate.c \
	   ../utils/error.c \
	   ../utils/get_info_utils.c \
	   ../utils/validate_map_utils.c 
	   

OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIB = ../minilibx-linux/libmlx.a
LIBS = -L../minilibx-linux -lmlx -lX11 -lXext
INCLUDES = -I../minilibx-linux

GREEN  = \033[0;32m
YELLOW = \033[0;33m
RESET  = \033[0m

.SILENT:


all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compilada$(RESET)"

$(NAME): $(LIBFT) $(OBJS) $(MINILIB)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME) $(LIBS)
	@echo "$(GREEN)✓ teste compilado com sucesso!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re valgrind