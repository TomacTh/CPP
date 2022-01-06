NAME		= ./ex01
SRC			=  ./main.cpp ./span.cpp
OBJ			= $(SRC:.cpp=.o)
FLAGS		= -Wall -Wextra -Werror -g  -std=c++98

all			: $(NAME)

$(NAME)		: $(OBJ)
			clang++ $(FLAGS) -lm -o $@ $^

%.o			: %.cpp
			clang++ $(FLAGS) -o $@ -c $^

clean		:
			rm -rf *.o

fclean		: clean
			rm -rf $(NAME)

re			: fclean all
