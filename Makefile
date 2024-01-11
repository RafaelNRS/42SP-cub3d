# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 07:47:02 by ranascim          #+#    #+#              #
#    Updated: 2024/01/11 15:41:46 by mleonard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Mandatory part
NAME			= cub3D
HEADER_DIR		= ./include/
HEADER			= cub3D.h
HEADER_PATH		= $(addprefix $(HEADER_DIR), $(HEADER))
SRC_DIR			= ./src/
SRC				=	main.c \
					errors/throw_err.c \
					validation/input_validation.c \
					validation/scene_validation.c \
					initialization/scene_initialization.c \
					initialization/game_initialization.c \
					initialization/feed_textures_and_colors.c \
					initialization/feed_textures_and_colors_2.c \
					initialization/feed_textures_and_colors_3.c \
					initialization/rgb_funcs.c \
					initialization/rgb_utils.c \
					initialization/feed_map.c \
					initialization/feed_map_2.c \
					close_utils/close_scene.c \
					close_utils/close_all.c  \
					utils/math_utils.c \
					utils/key_utils.c \
					utils/ray_utils.c \
					utils/draw_utils.c \
					utils/draw_utils2.c \
					game/main_game.c \
					game/move.c
SRC_PATH		= $(addprefix $(SRC_DIR), $(SRC))

# Libft
LIBFT_DIR		= ./lib/libft/
LIBFT 			= $(LIBFT_DIR)/libft.a
HEADER_LIBFT	= $(addprefix $(LIBFT_DIR), include/)

# Compiler and flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g3
MLXFLAGS		= -lmlx -lX11 -lXext -lm

# Binaries
BIN				= ./bin/
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

# Colors
OFF				:= \033[0m
RED				:= \033[0;31m
GREEN			:= \033[0;32m
BLUE			:= \033[0;34m


all: $(BINARY_OUT)

$(BINARY_OUT): $(SRC_PATH) $(HEADER_PATH)
	@ echo "$(BLUE)Compiling libft...$(OFF)"
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ echo "$(GREEN)Libft compiled successfully! $(OFF)"
	@ echo "$(BLUE)Compiling $(NAME)...$(OFF)"
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft $(MLXFLAGS) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(GREEN)$(NAME) compiled successfully!$(OFF)"

clean:
	@ echo "$(BLUE)Erasing libft files...$(OFF)"
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ echo "$(RED)Libft object files erased successfully!$(OFF)"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ echo "$(BLUE)Erasing files related to $(NAME)...$(OFF)"
	@ rm -f $(BINARY_OUT)
	@ rm -rf $(BIN)
	@ echo "$(RED)$(NAME) binaries erased successfully!$(OFF)"

re: fclean all

leaks:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft $(MLXFLAGS) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(GREEN)$(NAME) with leak check option compiled successfully!$(OFF)"

simple:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft $(MLXFLAGS) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(GREEN)$(NAME) without compile flags compiled successfully!$(OFF)"

.PHONY: all clean fclean re
