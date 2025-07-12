# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 09:55:58 by fmalungo          #+#    #+#              #
#    Updated: 2025/07/07 09:56:01 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = convert

CXX = c++

CXXFLAGS = -Wall -Wall -Werror -std=c++98

SRCS = main.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = ScalarConverter.hpp

$(NAME): $(HEADERS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re