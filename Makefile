NAME = so_long

SRC = so_long.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c textures.c map.c

CC = cc -fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

all : header ${NAME} 


.c.o:
	$(CC) $(CFLAGS) -c  $< -o $@ 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
		rm -f ${OBJ}

fclean : clean
		rm -f ${NAME}

re : fclean all

WHITE = \033[0;97m
NC = \033[0m
GREEN = \033[1;32m
header:
	@printf "$(WHITE)###############################################################$(NC)\n"

	@echo "$(GREEN)"
	@echo "███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ "
	@echo "██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ "
	@echo "███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗"
	@echo "╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║"
	@echo "███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝"
	@echo "╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ "
	@echo "$(NC)"  
	@printf "$(WHITE)##############################################################$(NC)\n"