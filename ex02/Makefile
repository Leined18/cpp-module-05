NAME = form_test

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc/ -fsanitize=address

SRC_DIR = .
OBJ_DIR = obj

SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/Bureaucrat.cpp \
       $(SRC_DIR)/MyException.cpp \
	   $(SRC_DIR)/AForm.cpp \
	   $(SRC_DIR)/ShrubberyCreationForm.cpp \
	   $(SRC_DIR)/RobotomyRequestForm.cpp \
	   $(SRC_DIR)/PresidentialPardonForm.cpp \
	   
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

# Compila y enlaza
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los .cpp en obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crea el directorio obj si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re