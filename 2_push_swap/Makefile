SRCS_PS	= 	srcs/push_swap/create_stack.c \
			srcs/push_swap/create_stack_utils.c \
			srcs/push_swap/large_sort.c \
			srcs/push_swap/large_sort_utils1.c \
			srcs/push_swap/large_sort_utils2.c \
			srcs/push_swap/list_utils.c \
			srcs/push_swap/math_utils.c \
			srcs/push_swap/push_swap.c \
			srcs/push_swap/tiny_sort.c \
			srcs/push_swap/tiny_sort_utils.c \
			srcs/push_swap/swap_oper_utils.c \
			srcs/push_swap/swap_opers1.c \
			srcs/push_swap/swap_opers2.c \
			srcs/push_swap/swap_opers3.c


SRCS_CH	=	srcs/checker/checker.c \
			srcs/push_swap/create_stack.c \
			srcs/push_swap/create_stack_utils.c \
			srcs/push_swap/swap_oper_utils.c \
			srcs/push_swap/list_utils.c \
			srcs/checker/get_next_line.c \
			srcs/checker/get_next_line_utils.c \
			srcs/checker/ch_swap_opers1.c \
			srcs/checker/ch_swap_opers2.c \
			srcs/checker/ch_swap_opers3.c

HEADERS		= includes/push_swap.h \
			includes/checker.h

OBJS_PS		= $(SRCS_PS:.c=.o)
OBJS_CH		= $(SRCS_CH:.c=.o)

LIBFT		= libft/libft.a

NAME_PS		= push_swap
NAME_CH		= checker

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.

$(NAME_PS):		$(OBJS_PS)
			$(MAKE) -C libft/
			cp $(LIBFT) $(NAME_PS)
			$(CC) -o $(NAME_PS) $(OBJS_PS) $(LIBFT)
	
$(NAME_CH):		$(OBJS_CH)
			$(MAKE) -C libft/
			cp $(LIBFT) $(NAME_CH)
			$(CC) -o $(NAME_CH) $(OBJS_CH) $(LIBFT)

all:	$(NAME_PS) $(NAME_CH)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean_push_swap: 
			$(MAKE) clean -C libft/
			$(RM) $(OBJS_PS)

clean_checker:
			$(MAKE) clean -C libft/
			$(RM) $(OBJS_CH)

clean:		clean_checker clean_push_swap

fclean_push_swap:	clean_push_swap
			$(RM) push_swap

fclean_checker:		clean_checker
			$(RM) checker

fclean:	fclean_checker fclean_push_swap
			$(MAKE) fclean -C libft/
			$(RM) libft.a		

re:		fclean all

.PHONY: all clean fclean re