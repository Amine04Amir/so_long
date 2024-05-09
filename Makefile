NAME = so_long

SRC = so_long.c textures.c map.c utils.c game.c movement.c floodfill.c \
      ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

PRINTF = ./ft_printf/libftprintf.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror

all : ${NAME} 

%.o:%.c
	$(CC) $(CFLAGS) -c  $< -o $@ 

$(PRINTF) : 
	MAKE -C ./ft_printf

OBJ = ${SRC:.c=.o}

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(PRINTF) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
		rm -f ${OBJ}
		make clean -C ./ft_printf
		make fclean -C ./ft_printf
fclean : clean
		rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)
