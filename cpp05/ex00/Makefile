# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 01:34:13 by sgerace           #+#    #+#              #
#    Updated: 2023/07/01 04:58:52 by sgerace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -g -Wall -Wextra -Werror -std=c++98

TARGET = bureaucrat

SRCS = 	main.cpp \
		Bureaucrat.cpp \

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	c++ $(FLAGS) $^ -o $@

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all