# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candrese <candrese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 15:54:47 by candrese          #+#    #+#              #
#    Updated: 2025/02/11 19:19:19 by candrese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17 #-g3 -fsanitize=address

SRCS = main.cpp Cat.cpp Dog.cpp Animal.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
