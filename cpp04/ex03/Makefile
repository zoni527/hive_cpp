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

NAME		:= abstract_class

CXX			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++20
DEBUG_FLAGS	:= -g
# ---------------------------------------------------------------------------- #
INC_DIR		:= ./inc
HEADERS		:= $(INC_DIR)/AMateria.hpp			\
			   $(INC_DIR)/Ice.hpp				\
			   $(INC_DIR)/Cure.hpp				\
			   $(INC_DIR)/ICharacter.hpp		\
			   $(INC_DIR)/Character.hpp			\
			   $(INC_DIR)/IMateriaSource.hpp	\
			   $(INC_DIR)/MateriaSource.hpp
# ---------------------------------------------------------------------------- #
SRC_DIR	:=	./src
OBJ_DIR	:=	./obj
# ---------------------------------------------------------------------------- #
SRC	:=	$(SRC_DIR)/AMateria.cpp			\
		$(SRC_DIR)/Ice.cpp				\
		$(SRC_DIR)/Cure.cpp				\
		$(SRC_DIR)/Character.cpp		\
		$(SRC_DIR)/MateriaSource.cpp	\
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
