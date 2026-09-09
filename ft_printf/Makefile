NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printchar.c ft_printnumber.c ft_printhexa.c ft_printunsigned.c \
ft_printpointer.c ft_printstr.c ft_printf.c \

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

all: $(NAME)


$(OBJ): $(HEADER)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re