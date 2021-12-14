NAME = sample.out
SRC = main.c window.c image.c moves.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@rm $(OBJ)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)