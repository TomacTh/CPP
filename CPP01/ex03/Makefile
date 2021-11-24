NAME		= ex03
SRC			= ./HumanA.cpp ./HumanB.cpp ./Weapon.cpp ./main.cpp
OBJ			= $(SRC:.cpp=.o)
FLAGS		= -Wall -Wextra -Werror -g -std=c++98

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
