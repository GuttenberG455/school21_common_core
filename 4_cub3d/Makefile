NAME = cub3D

CC = gcc
FLAGS = -g
RM = rm -f
# FLAGS = -Wall -Wextra -Werror

HEADERS =	./src/cub3d.h \
			./src/const.h \
			./src/libftv2/ft_zalloc/ft_zalloc.h \
			./src/libftv2/libftv2.h \
			./src/libftv2/libft/libft.h \
			./src/env/env.h \
			./src/error/error.h \
			./src/hooks/hooks.h \
			./src/parser/parser.h \
			./src/render/render.h \
			./src/vector/vector.h

LIBFT = ./src/libftv2/libft.a

MLXFLAGS	=	-L ./src/minilibx/ -lmlx -framework OpenGL -framework AppKit -lz
MLXDIR		=	./src/minilibx/

MAIN_SRCS	=	main \
				env/env \
				error/error \
				hooks/hooks \
				parser/check_properties \
				parser/get_properties \
				parser/get_map \
				parser/validate_input \
				render/image \
				render/raycasting \
				render/render_minimap \
				render/render_walls \
				render/render \
				vector/vector_operations1 \
				vector/vector_operations2

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