# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 13:43:27 by kkleinsc          #+#    #+#              #
#    Updated: 2022/08/29 13:31:27 by kkleinsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

NAME = philo

SRC =	main.c\
		input.c\
		util.c\
		philo.c\
		error.c\
		time.c

OBJ = ${SRC:.c=.o}

.PHONY: all clean fclean re libft bonus

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 