NAME =libft.a

CC =gcc

CFLAGS = -Wall -Werror -Wextra -c

HEADER = libft.h

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c\
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c\
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_print_c.c \
		ft_print_d.c \
		ft_print_hex.c \
		ft_print_p.c \
		ft_print_percent.c \
		ft_print_s.c \
		ft_print_u.c \
		ft_print_uns_itoa.c \
		ft_print_x.c \
		ft_print_xup.c \
		ft_printf.c \
		get_next_line.c \
		get_next_line_utils.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $^


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
