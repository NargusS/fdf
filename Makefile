# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 18:56:55 by achane-l          #+#    #+#              #
#    Updated: 2021/11/15 23:57:41 by achane-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	test

MINILIBX_DIR := minilibx-linux/
NAME_MINILIBX := libmlx.a
SRCS =	main.c\
		draw_line.c\
		get_line.c

OBJS := ${SRCS:.c=.o}

all: ${NAME}
	@printf "That's compile\n"
$(NAME): ${OBJS}
	make -C $(MINILIBX_DIR)
	@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJS) $(MINILIBX_DIR)$(NAME_MINILIBX) -lXext -lX11 -lm -lbsd
clean:
	@rm -f $(OBJS) $(MINILIBX_DIR)*.o
	@printf "Soft Cleaning\n"

fclean: clean
	@rm -f $(NAME) $(MINILIBX_DIR)$(NAME_MINILIBX)

re:	fclean all

PHONY: all bonus clean fclean re