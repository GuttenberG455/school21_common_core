
SRCS	=	srcs/ft_printf.c srcs/ft_print_c.c srcs/ft_print_d.c \
			srcs/ft_print_x.c srcs/ft_print_one.c srcs/ft_print_p.c \
			srcs/ft_print_s.c srcs/ft_print_u.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a
HEADER		= srcs/ft_printf.h
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