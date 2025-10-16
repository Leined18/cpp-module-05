
FLAGS = -Wextra -Werror -Wall -std=c++98 -fsanitize=address -g3
CPP = c++ 
FILES = main.cpp Bureaucrat.cpp MyException.cpp
INC = inc/

all: test


test: $(FILES)
	$(CPP) $(FLAGS) $(FILES) -I $(INC) -o test

fclean:
	@rm -rf test