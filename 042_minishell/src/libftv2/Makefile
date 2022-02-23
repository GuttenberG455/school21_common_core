# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:56:00 by ubeetroo          #+#    #+#              #
#    Updated: 2022/02/23 14:34:52 by majacqua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

COMP = gcc

FLAGS = -Wall -Werror -Wextra

LIB_PATH = ./libft/

LTM_PATH = ./libftmp/

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
				ft_strlen_printf \
				ft_multi_join


MAL_SRCS =		ft_zalloc \
				ftmp_zalloc 

LTM_SRCS =		ftmp_gnl_ut \
				ftmp_gnl \
				ftmp_itoa \
				ftmp_lstmap \
				ftmp_lstnew \
				ftmp_mult_join \
				ftmp_split \
				ftmp_strdup \
				ftmp_strjoin \
				ftmp_strmapi \
				ftmp_strtrim \
				ftmp_substr

LIB_SRC = $(addprefix $(LIB_PATH), $(LIB_SRCS))

LTM_SRC = $(addprefix $(LTM_PATH), $(LTM_SRCS))

MAL_SRC = $(addprefix $(MAL_PATH), $(MAL_SRCS))

ALL_SRC = $(LIB_SRC) $(MAL_SRC) $(LTM_SRC)

SRC =  $(addsuffix .c, $(ALL_SRC))
OBJ =  $(addsuffix .o, $(ALL_SRC))

# SRC_B =  $(addsuffix .c, $(SRCS_B))
# OBJ_B =  $(addsuffix .o, $(SRCS_B))

LIB_INC = ./libft/libft.h 
LTMP_INC = ./libftmp/libftmp.h 
MAL_INC = ./ft_zalloc/ft_zalloc.h

ALL_INC = $(LIB_INC) $(LTM_INC) $(MAL_INC)

INC = $(addprefix -I, $(ALL_PATHS))

$(NAME): $(OBJ) $(ALL_INC)
	ar rcs $@ $^

# bonus: $(OBJ) $(OBJ_B) 
# 	ar rcs $(NAME) $(OBJ) $(OBJ_B)

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@ $(INC)

all: $(NAME)

clean: 
	rm -f $(OBJ) 
#	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re