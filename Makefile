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
		rm -f ${OBJ} $(OBJ_BONUS)
		make clean -C ./ft_printf

fclean : clean
		rm -f ${NAME} $(NAME_BONUS)
		make fclean -C ./ft_printf

re : fclean all




NAME_BONUS = so_long_bonus

SRC_BONUS = ./bonus/so_long_bonus.c ./bonus/utils_bonus.c ./bonus/textures_bonus.c ./bonus/movement_bonus.c ./bonus/map_bonus.c ./bonus/game_bonus.c ./bonus/floodfill_bonus.c \
			./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

bonus : $(NAME_BONUS)

OBJ_BONUS = $(SRC_BONUS:.c=.o)


$(NAME_BONUS) : $(OBJ_BONUS) $(PRINTF)
	$(CC) $(PRINTF) $(OBJ_BONUS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

.SECONDARY: $(OBJ) $(OBJ_BONUS)

