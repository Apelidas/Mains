
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = brainz

SRC =	main.cpp

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

test:
	./brainz file "test" "vector"
	./brainz fileempty "test" "vector"
	./brainz file1 "" "vector"
	./brainz file2 "test" ""
