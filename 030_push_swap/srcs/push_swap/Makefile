SRCS	=	create_stack.c \
			create_stack_utils.c \
			large_sort.c \
			large_sort_utils1.c \
			large_sort_utils2.c \
			list_utils.c \
			math_utils.c \
			push_swap.c \
			tiny_sort.c \
			tiny_sort_utils.c \
			swap_oper_utils.c \
			swap_opers1.c \
			swap_opers2.c \
			swap_opers3.c 

OBJS		= $(SRCS:.c=.o)

NAME		= push_swap
HEADER		= ../../includes/push_swap.h
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