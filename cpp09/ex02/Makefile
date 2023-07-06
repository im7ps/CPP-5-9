# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 23:47:15 by sgerace           #+#    #+#              #
#    Updated: 2023/07/06 17:17:09 by sgerace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe
CC		=	c++
CFLAGS	=	#-std=c++98 -Wall -Wextra -Werror

SRCS	=	main.cpp \
			PmergeMe.cpp
			
all		:	$(NAME)

$(NAME)	:	$(SRCS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean	:
			@ rm -f $(NAME)

fclean 	:	clean

re 		: 	fclean all

.PHONY	:	all clean fclean re