# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 15:25:07 by kkleinsc          #+#    #+#              #
#    Updated: 2022/03/28 15:06:38 by kkleinsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

NAME = libftprintf.a

SRC =	ft_printf.c	\
		output.c	\
		tostring.c

OBJ = ${SRC:.c=.o}

$(NAME):$(OBJ)
	ar -r $(NAME) $(OBJ)

.PHONY: all clean fclean re
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 