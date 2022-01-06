NAME		= ex03
SRC			=  ./AMateria.cpp ./Character.cpp ./Cure.cpp ./Ice.cpp ./MateriaSource.cpp ./main.cpp
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
			rm -rf $(NAME)

re			: fclean all
