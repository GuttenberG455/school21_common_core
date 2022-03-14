SRCS =		main.c \
			init.c \
			launch.c \
			utils.c \
			eat.c

HEADERS = 	philo.h

OBJS =		$(SRCS:.c=.o)

NAME =		philo

CC			= gcc 
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.

LINKS		= -lpthread

$(NAME):		$(OBJS)
			$(CC) $(OBJS) $(LINKS) $(LIBFT) -o $(NAME) 

all:			$(NAME)

%.o:			%.c $(HEADERS) Makefile
			$(CC) $(FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re