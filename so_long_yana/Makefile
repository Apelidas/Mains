# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydimitro <ydimitro@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 20:00:05 by ydimitro          #+#    #+#              #
#    Updated: 2022/12/09 20:00:05 by ydimitro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/

SRC 		= so_long.c		\
			map_check.c		\
			game_close.c	\
			free_memory.c	\
			input_frame.c	\
			game_init.c		\
			map_init.c		\
			map_render.c	\
			utils.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): libft $(OBJ) mlx
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit


mlx:
	make -C mlx/

libft:
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY:			all clean fclean re libft mlx
