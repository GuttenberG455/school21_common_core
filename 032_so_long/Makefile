SRCS =		srcs/parser/check_map_utils.c \
			srcs/parser/check_map.c \
			srcs/parser/create_map.c \
			srcs/parser/create_map.c \
			srcs/parser/get_dimensions.c \
			srcs/parser/get_grid.c \
			srcs/parser/get_next_line_utils.c
			
SRCS_BONUS = 

HEADERS = includes/get_grid.h \
			includes/get_map.h


OBJS =		$(SRCS_PS:.c=.o)

LIBFT =		libft/libft.a

NAME =		so_long

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

all:			$(NAME)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re