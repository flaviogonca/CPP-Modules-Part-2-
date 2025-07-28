# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 12:44:17 by fmalungo          #+#    #+#              #
#    Updated: 2025/07/23 12:44:18 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Span.cpp

HEADER = Span.hpp

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
