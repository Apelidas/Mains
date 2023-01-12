
CC = gcc

LIBFT = ../libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = minishell

SRC =	main.c\
		input.c\
		input_util.c\
		error.c\
		lst.c\
		banana_split.c\
		var.c\
		var_util.c\
		in_out.c

OBJ = ${SRC:.c=.o}

.PHONY: all clean fclean re libft bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ../libft/libft.a -o $@ -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline

$(LIBFT):
	make -C ../libft/

clean:
	make clean -C ../libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ../libft/
	rm -f $(NAME)

re: fclean all 