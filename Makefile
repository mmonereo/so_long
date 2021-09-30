# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 16:39:49 by mmonereo          #+#    #+#              #
#    Updated: 2021/09/29 15:43:37 by mmonereo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBFT_DIR		= libft

LIBFT			= libft.a

MLX_DIR			= mlx

MLX				= libmlx.dylib

SRCS			=	check_map.c error.c keys.c map.c lst.c \
					mlx_init.c player.c point_map.c sprites.c wall.c main.c

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
				gcc $(CFLAGS) $(OBJS) $(LIBFT) $(LINK) -o $(NAME)
				

%.o: 			%.c
				gcc $(CFLAGS) -c $(SRCS)

clean:
				$(RM) $(OBJS) $(LIBFT) $(MLX)
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(MLX_DIR) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re 