SRCS =		srcs/parser/check_map_utils.c \
			srcs/parser/check_map.c \
			srcs/parser/create_map.c \
			srcs/parser/get_dimensions.c \
			srcs/parser/get_grid.c \
			srcs/parser/get_next_line_utils.c \
			srcs/parser/print_utils.c \
			srcs/game/draw_map.c \
			srcs/game/draw_map_utils.c \
			srcs/game/hooks.c \
			srcs/game/image.c \
			srcs/game/movements.c \
			srcs/game/movements_utils.c \
			srcs/game/window.c \
			srcs/game/so_long.c \
			
SRCS_BONUS = 

HEADERS = includes/get_grid.h \
			includes/get_map.h \
			includes/game.h


OBJS =		$(SRCS:.c=.o)

# LIBFT =		libft/libft.a

NAME =		so_long

CC			= gcc
RM			= rm -f
# FLAGS		= -Wall -Wextra -Werror -I.
LINKS = -lmlx -framework OpenGL -framework AppKit

$(NAME):		$(OBJS)
			$(CC) $(OBJS) $(LINKS) -o $(NAME)

all:			$(NAME)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re