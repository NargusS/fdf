# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 18:56:55 by achane-l          #+#    #+#              #
#    Updated: 2021/12/06 19:26:12 by achane-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf

MINILIBX_DIR := minilibx-linux/
NAME_MINILIBX := libmlx.a
SRCS =	src/fdf.c\
		src/config_view.c\
		src/read_maps.c\
		src/colors.c\
		src/utils_mlx_img.c\
		src/utils_free.c\
		src/linked_list.c\
		src/utils_read.c\
		src/init.c\
		src/events.c\
		src/utils.c\
		src/bresenham.c\
		src/print_map.c\
		src/utils_line.c\
		get_next_line/get_next_line_utils.c\
		get_next_line/get_next_line.c
OBJS := ${SRCS:.c=.o}

all: ${NAME}
	@printf "That's compile\n"
$(NAME): ${OBJS}
	make -C $(MINILIBX_DIR)
	@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJS) $(MINILIBX_DIR)$(NAME_MINILIBX) -no-pie -lXext -lX11 -lm -lbsd
clean:
	@rm -f $(OBJS) $(MINILIBX_DIR)*.o
	@printf "Soft Cleaning\n"

fclean: clean
	@rm -f $(NAME) $(MINILIBX_DIR)$(NAME_MINILIBX)

re:	fclean all

PHONY: all bonus clean fclean re