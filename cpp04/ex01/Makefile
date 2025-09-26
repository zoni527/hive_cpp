# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 12:04:28 by jvarila           #+#    #+#              #
#    Updated: 2025/06/12 10:21:14 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= i_dont_want_to_set_the_world_on_fire

CXX			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++20
DEBUG_FLAGS	:= -g
# ---------------------------------------------------------------------------- #
INC_DIR		:= ./inc
HEADERS		:= $(INC_DIR)/Animal.hpp		\
			   $(INC_DIR)/Dog.hpp			\
			   $(INC_DIR)/Cat.hpp			\
			   $(INC_DIR)/Brain.hpp
# ---------------------------------------------------------------------------- #
SRC_DIR	:=	./src
OBJ_DIR	:=	./obj
# ---------------------------------------------------------------------------- #
SRC :=	$(SRC_DIR)/Animal.cpp		\
		$(SRC_DIR)/Dog.cpp			\
		$(SRC_DIR)/Cat.cpp			\
		$(SRC_DIR)/Brain.cpp		\
		$(SRC_DIR)/main.cpp
# ---------------------------------------------------------------------------- #
OBJ :=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

.SECONDARY: $(OBJ)
# ---------------------------------------------------------------------------- #
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -I $(INC_DIR) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CXX) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
# ---------------------------------------------------------------------------- #
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
# ---------------------------------------------------------------------------- #
debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean all
# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re debug
# ---------------------------------------------------------------------------- #
