# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 13:43:27 by kkleinsc          #+#    #+#              #
#    Updated: 2022/08/22 12:41:09 by kkleinsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror 

NAME = pipex

SRC =	main.c\
		input.c\
		input_util.c\
		child.c\
		parent.c\
		bonus.c\
		bonus_util.c

OBJ = ${SRC:.c=.o}

.PHONY: all clean fclean re libft bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $@

$(LIBFT):
	make -C libft/

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all 