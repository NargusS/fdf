# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 18:56:55 by achane-l          #+#    #+#              #
#    Updated: 2021/11/22 11:24:24 by achane-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf

MINILIBX_DIR := minilibx-linux/
NAME_MINILIBX := libmlx.a
SRCS =	main.c\
		draw_line.c\
		utils_1.c\
		utils_2.c\
		read_maps.c\
		print_map.c\
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