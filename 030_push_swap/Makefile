SRCS	=	srcs/create_stack.c srcs/create_stack_utils.c srcs/large_sort.c srcs/large_sort_utils1.c \
			srcs/list_utils.c srcs/main.c srcs/tiny_sort.c srcs/tiny_sort_utils.c \
			srcs/swap_oper_utils.c srcs/task_swap_op1.c srcs/task_swap_op2.c srcs/task_swap_op3.c 

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