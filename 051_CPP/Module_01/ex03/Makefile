SRCS	= main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

HEADERS = Weapon.hpp \
		HumanA.hpp \
		HumanB.hpp


OBJS	= $(SRCS:.cpp=.o)

NAME	= out

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