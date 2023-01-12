
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = Account

SRC =	Account.cpp\
		tests.cpp

OBJ = ${SRC:.c=.o}

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all
