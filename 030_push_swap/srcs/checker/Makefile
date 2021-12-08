SRCS	=	checker.c \
			../push_swap/create_stack.c \
			../push_swap/create_stack_utils.c \
			../push_swap/swap_oper_utils.c \
			../push_swap/list_utils.c \
			get_next_line.c \
			get_next_line_utils.c \
			ch_swap_opers1.c \
			ch_swap_opers2.c \
			ch_swap_opers3.c

OBJS		= $(SRCS:.c=.o)

NAME		= checker
HEADER		= ../../includes/checker.h
LIBFT		= ../../libft/libft.a

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.

all:		$(NAME)

$(NAME): 	$(OBJS)
				$(MAKE) -C ../../libft
				cp $(LIBFT) $(NAME)
				$(CC) -o $(NAME) $(OBJS) $(LIBFT)

%.o:		%.c $(HEADER)
				$(CC) $(FLAGS) -c $< -o $@

clean:
				$(MAKE) clean -C ../../libft
				$(RM) $(OBJS)

fclean:		clean
				$(MAKE) fclean -C ../../libft
				$(RM) $(NAME)
				$(RM) libft.a

re:			fclean all

.PHONY:		all clean fclean re 