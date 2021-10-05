# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 16:39:49 by mmonereo          #+#    #+#              #
#    Updated: 2021/10/05 16:30:53 by mmonereo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBFT_DIR		= libft

LIBFT			= libft.a

MLX_DIR			= mlx

MLX				= libmlx.dylib

SRCS			=	check_map.c check_map2.c error.c keys.c map.c lst.c sprites_2.c \
					mlx_init.c player.c point_map.c sprites.c paint_map.c main.c aux.c

OBJS			= $(SRCS:.c=.o)

RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
LINK			= -Lmlx -lmlx -framework OpenGL -framework AppKit

all:			$(NAME)

$(LIBFT):
				@cd $(LIBFT_DIR) && $(MAKE)

$(MLX):
				@cd $(MLX_DIR) && $(MAKE)

$(NAME):		$(OBJS) $(LIBFT) $(MLX)
				@cp $(LIBFT_DIR)/$(LIBFT) .
				@cp $(MLX_DIR)/$(MLX) .
				gcc $(CFLAGS) $(OBJS) $(LIBFT) $(LINK) -o $@

%.o: 			%.c
				gcc $(CFLAGS) -c $< 

clean:
				$(RM) $(OBJS) $(LIBFT) $(MLX)
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(MLX_DIR) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re 