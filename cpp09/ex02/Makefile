# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 12:04:28 by jvarila           #+#    #+#              #
#    Updated: 2025/10/13 16:48:23 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= PmergeMe

CXX			:= c++
CXX_FLAGS	:= -Wall -Wextra -Werror -std=c++17
DEBUG_FLAGS	:= -DDEBUG -g
# ---------------------------------------------------------------------------- #
INC_DIR		:= ./inc
HEADERS		:= $(INC_DIR)/PmergeMe.hpp
# ---------------------------------------------------------------------------- #
SRC_DIR	:=	./src
OBJ_DIR	:=	./obj
# ---------------------------------------------------------------------------- #
SRC :=	$(SRC_DIR)/PmergeMe.cpp	\
		$(SRC_DIR)/main.cpp
# ---------------------------------------------------------------------------- #
OBJ :=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

.SECONDARY: $(OBJ)
# ---------------------------------------------------------------------------- #
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXX_FLAGS) -I $(INC_DIR) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) -I $(INC_DIR) -c $< -o $@
# ---------------------------------------------------------------------------- #
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
# ---------------------------------------------------------------------------- #
UPPER_LIMIT	?= 1000
LOWER_LIMIT	?= -1000
AMOUNT		?= 100

run: $(NAME)
	@./$(NAME) `seq $(LOWER_LIMIT) $(UPPER_LIMIT)\
	| shuf -r -n $(AMOUNT) | tr "\n" " "`
	@./validate.sh

gdb: $(NAME)
	gdb -tui $(NAME)

ddb: debug gdb
# ---------------------------------------------------------------------------- #
debug: CXX_FLAGS += $(DEBUG_FLAGS)
debug: fclean all
# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re debug run gdb ddb
# ---------------------------------------------------------------------------- #
