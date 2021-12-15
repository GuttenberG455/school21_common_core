NAME = so_long.out
SRC = so_long.c window.c image.c draw_map.c draw_map_utils.c hooks.c \
			movements.c \
			movements_utils.c \
			../parser/check_map_utils.c \
			../parser/check_map.c \
			../parser/create_map.c \
			../parser/get_dimensions.c \
			../parser/get_grid.c \
			../parser/get_next_line_utils.c \
			../parser/print_utils.c

OBJ = $(SRC:.c=.o)

# FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)