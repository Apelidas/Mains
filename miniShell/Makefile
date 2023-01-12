
CC = gcc

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = minishell

SRC_PATH = 

IN = input/

EXEC = execute/

BUILT = builtin/

SRC =	$(IN)input.c\
		$(IN)input_util.c\
		$(IN)error.c\
		$(IN)lst.c\
		$(IN)banana_split.c\
		$(IN)var.c\
		$(IN)var_util.c\
		$(IN)in_out.c\
		$(IN)clean.c\
		$(IN)quotes.c\
		$(IN)redirect.c\
		$(IN)redirect_util.c\
		$(EXEC)child.c\
		$(EXEC)execute.c\
		$(EXEC)here_doc.c\
		$(EXEC)parent.c\
		$(BUILT)list_converter.c\
		$(BUILT)utils.c\
		$(BUILT)utils_2.c\
		$(BUILT)cd.c\
		$(BUILT)create_env_list.c\
		$(BUILT)echo.c\
		$(BUILT)env_utils.c\
		$(BUILT)free_splits_and_env.c\
		$(BUILT)export_cmd_0.c\
		$(BUILT)export_cmd_1.c\
		$(BUILT)export_utils.c\
		$(BUILT)pwd.c\
		$(BUILT)unset.c\
		$(BUILT)choose_builtin.c\
		$(BUILT)exit_cmd.c\
		signal.c\
		main.c

OBJ = ${SRC:.c=.o}

.PHONY: all clean fclean re libft bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $^ libft/libft.a -o $@ -I $(HOME)/goinfre/.brew/opt/readline/include/ -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline

$(LIBFT):
	make -C libft/

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all 