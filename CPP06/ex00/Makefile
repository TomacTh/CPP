NAME		= converter
SRC			=  ./main.cpp
OBJ			= $(SRC:.cpp=.o)
FLAGS		= -Wall -Wextra -Werror -g

all			: $(NAME)

$(NAME)		: $(OBJ)
			clang++ $(FLAGS) -lm -o $@ $^

%.o			: %.cpp
			clang++ $(FLAGS) -o $@ -c $^

clean		:
			rm -rf $(OBJ)

fclean		: clean
			rm -rf $(NAME)

re			: fclean all
