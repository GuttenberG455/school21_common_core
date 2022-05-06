# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:56:00 by ubeetroo          #+#    #+#              #
#    Updated: 2022/05/06 14:50:45 by majacqua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

COMP = gcc

FLAGS = -Wall -Werror -Wextra

LIB_PATH = ./libft/

MAL_PATH = ./ft_zalloc/

ALL_PATH = $(LIB_PATH)	$(MAL_PATH) $(LTM_PATH)

LIB_SRCS =		ft_atoi \
				ft_bzero \
				ft_calloc \
				ft_isalnum \
				ft_isalpha \
				ft_isascii \
				ft_isdigit \
				ft_isprint \
				ft_memchr \
				ft_memcmp \
				ft_memcpy \
				ft_memmove \
				ft_memset \
				ft_strchr \
				ft_strdup \
				ft_strlcat \
				ft_strlcpy \
				ft_strlen \
				ft_strncmp \
				ft_strnstr \
				ft_strrchr \
				ft_tolower \
				ft_toupper \
				ft_substr \
				ft_strjoin \
				ft_strtrim \
				ft_split \
				ft_itoa \
				ft_putchar_fd \
				ft_putstr_fd \
				ft_putendl_fd \
				ft_putnbr_fd \
				ft_strmapi \
				ft_striteri \
				ft_get_next_line_bonus \
				ft_get_next_line_utils_bonus \
				ft_pow \
				ft_lstnew \
				ft_lstadd_front \
				ft_lstsize \
				ft_lstlast \
				ft_lstadd_back \
				ft_lstdelone \
				ft_lstclear \
				ft_lstiter \
				ft_lstmap \
				ft_printf \
				ft_putchar_fd_printf \
				ft_putnbr_base_printf \
				ft_putnbr_basep_printf \
				ft_putnbr_fd_printf \
				ft_putstr_fd_printf \
				ft_multi_join \
				ft_split_len \
				ft_str_translate

MAL_SRCS =		ft_zalloc 

LIB_SRC = $(addprefix $(LIB_PATH), $(LIB_SRCS))

MAL_SRC = $(addprefix $(MAL_PATH), $(MAL_SRCS))

ALL_SRC = $(LIB_SRC) $(MAL_SRC)

SRC =  $(addsuffix .c, $(ALL_SRC))
OBJ =  $(addsuffix .o, $(ALL_SRC))

LIB_INC = ./libft/libft.h 
MAL_INC = ./ft_zalloc/ft_zalloc.h

ALL_INC = $(LIB_INC) $(MAL_INC)

INC = $(addprefix -I, $(ALL_PATHS))

$(NAME): $(OBJ) $(ALL_INC)
	ar rcs $@ $^

%.o: %.c Makefile $(ALL_INC)
	$(COMP) $(FLAGS) -c $< -o $@ $(INC)

all: $(NAME)

clean: 
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re