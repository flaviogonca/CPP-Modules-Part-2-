# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/12 17:14:18 by fmalungo          #+#    #+#              #
#    Updated: 2025/07/12 17:15:45 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize

CXX = c++

CXXFLAGS = -Wall -Wall -Werror -std=c++98

SRCS = main.cpp Serializer.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Serializer.hpp Data.hpp

$(NAME): $(HEADERS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
