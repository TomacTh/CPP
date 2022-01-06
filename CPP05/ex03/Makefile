NAME		= ex03
SRC			=  ./main.cpp ./Bureaucrat.cpp ./Form.cpp ./ShrubberyCreationForm.cpp ./PresidentialPardonForm.cpp ./RobotomyRequestForm.cpp ./Intern.cpp
FLAGS		= -Wall -Wextra -Werror -g  -std=c++98
OBJ			= $(SRC:.cpp=.o)

all			: $(NAME)

$(NAME)		: $(OBJ)
			clang++ $(FLAGS) -o $@ $^

%.o			: %.cpp
			clang++ $(FLAGS) -o $@ -c $^

clean		:
			rm -rf *.o

fclean		: clean
			rm -rf $(NAME)

re			: fclean all
