NAME = cub3D

CC = gcc
FLAGS = -g
RM = rm -f
# FLAGS = -Wall -Wextra -Werror

HEADERS =	./src/cub3d.h \
			./src/const.h \
			./src/libftv2/ft_zalloc/ft_zalloc.h \
			./src/libftv2/libftv2.h \
			./src/libftv2/libft/libft.h

LIBFT = ./src/libftv2/libft.a

MLXFLAGS	=	-L ./src/minilibx/ -lmlx -framework OpenGL -framework AppKit -lz
MLXDIR		=	./src/minilibx/

MAIN_SRCS	=	main \
				env/env \
				error/error \
				parser/validate_input \
				parser/get_map \
				parser/get_grid \
				render/image \
				render/render

MAIN_SRC = $(addprefix ./src/, $(addsuffix .c, $(MAIN_SRCS)))

MAIN_OBJ = $(addprefix ./src/, $(addsuffix .o, $(MAIN_SRCS)))

all: $(NAME)

$(NAME): $(LIBFT) $(MAIN_OBJ) $(HEADERS)
	@make -s -C ./src/libftv2/
	@make -s -C $(MLXDIR)
	$(CC) $(FLAGS) $(MAIN_OBJ) $(LIBFT) $(MLXFLAGS) -lm -o $(NAME)

%.o: %.c Makefile $(HEADERS)
	$(CC) $(FLAGS) -Imlx -c $< -o $@ -I./src/libftv2/libft/

$(LIBFT): ./src/libftv2/ft_zalloc/*.c ./src/libftv2/ft_zalloc/*.h ./src/libftv2/libft/*.c ./src/libftv2/libft/*.h ./src/libftv2/Makefile ./src/libftv2/libftv2.h
	make -C ./src/libftv2/

clean:
	$(RM) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME)
	make clean -s -C $(MLXDIR)
	make fclean -s -C ./src/libftv2/

run_doom: all
	./cub3D src/maps/doom.cub

run_wolf: all
	./cub3D src/maps/wolf.cub

run_anime: all
	./cub3D src/maps/anime.cub

run_test: all
	./cub3D src/maps/test.cub

re: fclean all

.PHONY: all clean fclean re run_doom run_wolf run_anime run_test