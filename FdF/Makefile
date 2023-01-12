# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 13:18:12 by kkleinsc          #+#    #+#              #
#    Updated: 2022/07/06 17:08:21 by kkleinsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = fdf

SRC =	GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		grid.c\
		data.c\
		input.c\
		row.c\
		vector.c\
		iso.c\
		line.c\
		color.c\
		rotate.c\
		zoom.c\
		main.c

OBJ = ${SRC:.c=.o}

.PHONY: all clean fclean re libft bonus

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L Libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

libft:
	make -C Libft/

clean:
	make clean -C Libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C Libft/
	rm -f $(NAME)

re: fclean all 