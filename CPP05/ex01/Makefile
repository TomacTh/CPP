NAME	:= ex01
CXX		:= clang++
CXXFLAGS	:= -Werror -Wall -Wextra -std=c++98
RM		:= rm -rf
FILES	:= ./main.cpp ./Bureaucrat.cpp ./Form.cpp
OBJS	:= $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $< -lm -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.Phony: all re fclean clean
