##
## EPITECH PROJECT, 2025
## new_workspace_creator
## File description:
## Makefile
##

CXX		= clang++

SRC     =	$(shell find src/ -wholename "*.cpp")

OBJ     = $(SRC:.cpp=.o)

NAME    = nanotekspice

VPATH = include/

CXXFLAGS += -Wall -Wextra -std=c++20

CPPFLAGS = -iquote $(VPATH) \

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

unit_tests: fclean
	g++ -o unit_tests tests/*.cpp src/nothing.cpp -lcriterion --coverage

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/ --branches
	gcovr --exclude tests/

clean:
	rm -rf $(OBJ)
	rm -rf *~
	rm -rf #*#
	rm -rf a.out
	rm -rf vgcore*
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.gcov

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS += -g3
debug: re

.PHONY: all clean fclean re debug tests_run
