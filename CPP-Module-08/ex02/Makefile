# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 19:31:55 by fmalungo          #+#    #+#              #
#    Updated: 2025/07/23 19:32:01 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Mutated_abomination

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

HEADER = MutantStack.hpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJ): $(HEADER)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
