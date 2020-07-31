# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/29 11:58:13 by yictseng          #+#    #+#              #
#    Updated: 2020/07/31 18:58:25 by yictseng         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 								VARIABLES									   #
# **************************************************************************** #

NAME 			= cub3D
PATH_HEADER		= includes/
PATH_SRCS		= srcs/
HEADER_LIST		= cub3d.h\
				  get_next_line.h\

SRCS_LIST		= check_map.c\
				  check_value.c\
				  check_wall.c\
				  draw_sprite.c\
				  draw_walls.c\
				  get_next_line.c\
				  get_next_line_utils.c\
				  get_texture.c\
				  init_variables.c\
				  main.c\
				  move_in_map.c\
				  parse_element.c\
				  parse_utils.c\
				  parsing.c\
				  print_screen.c\
				  run_cub3d.c\
				  run_raycasting.c\
				  write_error.c\

OBJS			= $(SRCS_LIST:.c=.o)

HEADER			= $(addprefix $(PATH_HEADER), $(HEADER_LIST))

MLX				= minilibx/libmlx.a

LIB_MLX			= -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit

CC 				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

# **************************************************************************** #
#  								REGLES									       #
# **************************************************************************** #

all				: $(MLX) $(NAME)

%.o				: $(PATH_SRCS)%.c $(HEADER)
			  	  $(CC) $(CFLAGS) -c $< -I $(HEADER)

$(MLX)			:
			  	  @$(MAKE) -C minilibx/

$(NAME)			: $(OBJS) $(HEADER)
				  $(CC) $(CFLAGS) $(LIB_MLX) $(OBJS) -o $(NAME)

clean			:
				  @$(MAKE) -C minilibx/ clean
				  @$(RM) $(OBJS)
				  @$(RM) screenshot.bmp

fclean			: clean
				  @$(RM) $(NAME)

re				: fclean all

.PHONY			: clean fclean all re