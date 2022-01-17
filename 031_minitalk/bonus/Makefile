SRCS_CL_B	=	client_bonus.c \
			utils_bonus.c

SRCS_SV_B	=	server_bonus.c \
			utils_bonus.c

HEADERS		= minitalk_bonus.h

OBJS_CL_B	= $(SRCS_CL_B:.c=.o)
OBJS_SV_B	= $(SRCS_SV_B:.c=.o)

LIBFT		= ../libft/libft.a

NAME_CL		= client
NAME_SV		= server

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.
	
all:	$(NAME_CL) $(NAME_SV)

$(NAME_SV):		$(OBJS_SV_B)
			$(MAKE) -C ../libft/
			cp $(LIBFT) $(NAME_SV)
			$(CC) -o $(NAME_SV) $(OBJS_SV_B) $(LIBFT)

$(NAME_CL):		$(OBJS_CL_B)
			$(MAKE) -C ../libft/
			cp $(LIBFT) $(NAME_CL)
			$(CC) -o $(NAME_CL) $(OBJS_CL_B) $(LIBFT)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean: 
			$(MAKE) clean -C ../libft/
			$(RM) $(OBJS_CL_B)
			$(RM) $(OBJS_SV_B)

fclean:			clean
			$(MAKE) fclean -C ../libft/
			$(RM) client
			$(RM) server

re:		fclean all

.PHONY: all clean fclean re bonus