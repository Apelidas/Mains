# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 15:25:07 by kkleinsc          #+#    #+#              #
#    Updated: 2022/06/19 15:13:00 by kkleinsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
NAME_BON = checker

SRC =	chunks.c	\
		input_check.c	\
		opCombo.c	\
		opsingle.c	\
		logic.c	\
		simulation.c	\
		sort.c	\
		command_fake.c	\
		list.c	\
		debug/debug.c	\
		header.c	\
		list_logic.c	\
		clean.c

MAN =	main.c
BON =	Bonus.c

OBJ_MAN = ${MAN:.c=.o}

OBJ_BON = ${BON:.c=.o}

OBJ = ${SRC:.c=.o}


.PHONY: all clean fclean re libft bonus

all: $(NAME) bonus

$(NAME): libft $(OBJ) $(OBJ_MAN)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_MAN) -o $(NAME) -L Libft -lft

bonus: $(OBJ) $(OBJ_BON)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BON) -o $(NAME_BON) -L Libft -lft

libft:
	make -C Libft/

clean:
	make clean -C Libft/
	rm -f $(OBJ)
	rm -f $(OBJ_MAN)
	rm -f $(OBJ_BON)

fclean: clean
	make fclean -C Libft/
	rm -f $(NAME)
	rm -f $(NAME_BON)

re: fclean all 