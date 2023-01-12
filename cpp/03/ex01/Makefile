
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = fixed

SRC =	main.cpp\
		ClapTrap.cpp\
		ScavTrap.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
