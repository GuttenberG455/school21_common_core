SRCS	=	srcs/

OBJS		= $(SRCS:.c=.o)

NAME		= push_swap
HEADER		= includes/push_swap.h
LIBFT		= libft/libft.a

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

all:		$(NAME)

$(NAME): 	$(OBJS)
				$(MAKE) -C ./libft
				cp $(LIBFT) $(NAME)
				ar rcs $(NAME) $(OBJS)
				ranlib $(NAME)

%.o:		%.c $(HEADER)
				$(CC) $(FLAGS) -c $< -o $@

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS)

fclean:		clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus