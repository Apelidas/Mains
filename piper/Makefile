# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 13:43:27 by kkleinsc          #+#    #+#              #
#    Updated: 2022/08/22 11:13:32 by kkleinsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

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

%.o: %.c
	$(CC) $(CFLAGS) $^

.PHONY: all clean fclean re libft bonus

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $@

libft:
	make -C libft/

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all 