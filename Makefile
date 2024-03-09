NAME = so_long

SRC = so_long.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c 

CC = gcc -fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

all : ${NAME} 


.c.o:
	$(CC) $(CFLAGS) -c  $< -o $@ 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
		rm -f ${OBJ}

fclean : clean
		rm -f ${NAME}

re : fclean all
