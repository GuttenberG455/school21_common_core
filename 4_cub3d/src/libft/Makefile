NAME = libft.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Werror -Wextra -c

SRC_FILES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_atoi.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strcmp.c \
		ft_remove_char.c \
		ft_isstrdigit.c \
		./ft_zalloc/ft_zalloc.c \
		./ft_get_next_line/get_next_line_utils.c \
		./ft_get_next_line/get_next_line.c
	
BONUS_FILES = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJECTS = $(SRC_FILES:.c=.o)
BON_OBJECTS = $(BONUS_FILES:.c=.o)

HEADER = libft.h ft_get_next_line/get_next_line.h ft_zalloc/ft_zalloc.h
LIBC = ar -rc
LIBR = ranlib

OBJS = $(OBJECTS) $(BON_OBJECTS)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(LIBC) $(NAME) $(OBJS) 
	@$(LIBR) $(NAME) 
	
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $< -o $@ 

bonus :
	@make all
	
clean:
	$(RM) $(OBJECTS) $(BON_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus 