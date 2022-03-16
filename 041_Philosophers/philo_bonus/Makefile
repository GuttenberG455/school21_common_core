SRCS =		main_bonus.c \
			init_bonus.c \
			launch_bonus.c \
			utils_bonus.c \
			thread_check_bonus.c

HEADERS = 	philo_bonus.h

OBJS =		$(SRCS:.c=.o)

NAME =		philo_bonus

CC			= gcc 
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.

LINKS		= -lpthread

$(NAME):		$(OBJS)
			$(CC) $(OBJS) $(LINKS) $(LIBFT) -o $(NAME)

all:			$(NAME)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re
