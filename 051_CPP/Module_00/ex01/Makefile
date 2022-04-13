SRCS	= main.cpp \
		Contact.cpp \
		PhoneBook.cpp

HEADERS = Contact.hpp \
		PhoneBook.hpp


OBJS	= $(SRCS:.cpp=.o)

NAME	= phone

CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
		$(CXX) $(OBJS) -o $(NAME)

%.o:		%.cpp Makefile
		$(CXX) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re