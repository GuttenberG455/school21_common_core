SRCS_CL	= 	srcs/client.c \
			srcs/utils.c

SRCS_SV	=	srcs/server.c \
			srcs/utils.c

HEADERS		= includes/minitalk.h

OBJS_CL		= $(SRCS_CL:.c=.o)
OBJS_SV		= $(SRCS_SV:.c=.o)


LIBFT		= libft/libft.a

NAME_CL		= client
NAME_SV		= server

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.
	
all:	$(NAME_CL) $(NAME_SV)

$(NAME_SV):		$(OBJS_SV)
			$(MAKE) -C libft/
			cp $(LIBFT) $(NAME_SV)
			$(CC) -o $(NAME_SV) $(OBJS_SV) $(LIBFT)

$(NAME_CL):		$(OBJS_CL)
			$(MAKE) -C libft/
			cp $(LIBFT) $(NAME_CL)
			$(CC) -o $(NAME_CL) $(OBJS_CL) $(LIBFT)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean: 
			$(MAKE) clean -C libft/
			$(MAKE) clean -C bonus/
			$(RM) $(OBJS_CL)
			$(RM) $(OBJS_SV)

fclean:			clean
			$(MAKE) fclean -C libft/
			$(MAKE) fclean -C bonus/
			$(RM) client
			$(RM) server

bonus: 
	@$(MAKE) -C bonus
	@cp bonus/$(NAME_SV) .
	@cp bonus/$(NAME_CL) .

re:		fclean all

.PHONY: all clean fclean re bonus