SRCS	= main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

HEADERS = Bureaucrat.hpp \
		Form.hpp \
		ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp \
		PresidentialPardonForm.hpp \
		Intern.hpp

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