# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 09:47:08 by fmalungo          #+#    #+#              #
#    Updated: 2025/07/13 09:47:10 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = realtype

CXX = c++

CXXFLAGS = -Wall -Wall -Werror -std=c++98

SRCS = main.cpp Base.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Base.hpp

$(NAME): $(HEADERS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
