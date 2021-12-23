SRCS =		srcs/so_long.c \
			srcs/window.c \
			srcs/init_map.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/check_map.c \
			srcs/draw_map.c \
			srcs/draw_map_utils.c \
			srcs/image.c \
			srcs/hooks.c \
			srcs/movements.c \
			srcs/movements_utils.c \
			srcs/ft_printf.c 
			
SRCS_BONUS = 

HEADERS = 	includes/map.h \
			includes/game.h

OBJS =		$(SRCS:.c=.o)

LIBFT =		libft/libft.a

NAME =		so_long

CC			= gcc 
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.
LINKS = -lmlx -framework OpenGL -framework AppKit

$(NAME):		$(OBJS)
			$(MAKE) -C libft/
			cp $(LIBFT) $(NAME)
			$(CC) $(OBJS) $(LINKS) $(LIBFT) -o $(NAME)

all:			$(NAME)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			$(MAKE) clean -C libft/
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)
			$(RM) libft.a
			$(MAKE) fclean -C libft/

re:				fclean all

.PHONY: all clean fclean re