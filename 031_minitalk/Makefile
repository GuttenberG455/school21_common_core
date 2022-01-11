SRCS_CL	= 	srcs/client.c

SRCS_SV	=	srcs/server.c

HEADERS		= includes/client.h \
			includes/server.h

OBJS_CL		= $(SRCS_CL:.c=.o)
OBJS_SV		= $(SRCS_SV:.c=.o)

LIBFT		= libft/libft.a

NAME_CL		= client
NAME_SV		= server

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.
	
$(NAME_SV):		$(OBJS_SV)
			$(MAKE) -C libft/
			cp $(LIBFT) $(NAME_SV)
			$(CC) -o $(NAME_SV) $(OBJS_SV) $(LIBFT)

$(NAME_CL):		$(OBJS_CL)
			$(MAKE) -C libft/
			cp $(LIBFT) $(NAME_CL)
			$(CC) -o $(NAME_CL) $(OBJS_CL) $(LIBFT)

all:	$(NAME_CL) $(NAME_SV)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean_client: 
			$(MAKE) clean -C libft/
			$(RM) $(OBJS_CL)

clean_server:
			$(MAKE) clean -C libft/
			$(RM) $(OBJS_SV)

clean:		clean_server clean_client

fclean_client:	clean_client
			$(RM) client

fclean_server:		clean_server
			$(RM) server

fclean:	fclean_server clean_client
			$(MAKE) fclean -C libft/
			$(RM) libft.a

re:		fclean all

.PHONY: all clean fclean re