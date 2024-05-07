NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils1.c ft_printf_utils2.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):$(OBJ)
		ar rcs $@ $^

%.o : %.c
		cc ${CFLAGS} -o $@ -c $^

clean :
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
