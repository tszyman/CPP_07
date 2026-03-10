# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/10 19:28:31 by tszymans          #+#    #+#              #
#    Updated: 2026/03/10 22:07:12 by tszymans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = array

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98
# The -I . flag tells the compiler to look for headers in the current directory
INCLUDES = -I .

SRCS    = main.cpp\

OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.cpp Array.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
