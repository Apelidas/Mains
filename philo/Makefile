# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkleinsc <kkleinsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 18:25:57 by kmeixner          #+#    #+#              #
#    Updated: 2022/05/06 18:24:02 by kkleinsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	checks.c clean.c exits.c ft_atoi.c init.c input.c philo.c \
				philroutine.c time.c utils.c

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -pthread -O3 -g -fsanitize=thread

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re