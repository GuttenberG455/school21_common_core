# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 11:36:13 by rusty             #+#    #+#              #
#    Updated: 2022/02/23 12:56:53 by majacqua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

COMP = gcc -g -Wall -Werror -Wextra -fsanitize=address

LIBFT = ./src/libftv2/libft.a

ENV_SRCS = 	env/set_param \
			env/get_param \
			env/del_param \
			env/env_init

PARS_SRCS = parser/cut_spaces \
			parser/put_global

ERR_SRCS =	error/error

SHELL_SRCS = shell/shell

MAIN_SRCS = $(ENV_SRCS)		$(PARS_SRCS) \
			$(SHELL_SRCS)	$(ERR_SRCS) \
			main

MAIN_SRC = $(addprefix ./src/, $(addsuffix .c, $(MAIN_SRCS)))

MAIN_OBJ = $(addprefix ./src/, $(addsuffix .o, $(MAIN_SRCS)))

all: $(NAME)

$(NAME): $(LIBFT) $(MAIN_OBJ)
	$(COMP) $(MAIN_OBJ) $(LIBFT) -o $@ -lreadline

%.o: %.c Makefile
	$(COMP) -c $< -o $@ -I./src/env/ -I./src/libftv2/libft/ 

$(LIBFT):
	make -C ./src/libftv2/

clean:
	rm -f $(MAIN_OBJ)
	make -C ./src/libftv2 fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re