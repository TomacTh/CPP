NAME		= ex02
SRC			=  ./main.cpp ./Bureaucrat.cpp ./Form.cpp ./ShrubberyCreationForm.cpp ./PresidentialPardonForm.cpp ./RobotomyRequestForm.cpp
OBJ			= $(SRC:.cpp=.o)
FLAGS		= -Wall -Wextra -Werror -g  -std=c++98

all			: $(NAME)

$(NAME)		: $(OBJ)
			clang++ $(FLAGS) -o $@ $^

%.o			: %.cpp
			clang++ $(FLAGS) -o $@ -c $^

clean		:
			rm -rf $(OBJ)

fclean		: clean
			rm -rf $(NAME) outfile_shruberry

re			: fclean all
