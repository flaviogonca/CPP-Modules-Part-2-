# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 15:21:50 by fmalungo          #+#    #+#              #
#    Updated: 2025/07/21 15:21:51 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

HEADER = easyfind.hpp

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
