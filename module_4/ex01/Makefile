# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 21:05:04 by dlacuey           #+#    #+#              #
#    Updated: 2024/06/27 11:21:02 by dlacuey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS =																		\
																			\
					main.o													\
					animals.o												\
					cat.o													\
					dog.o													\
					WrongAnimal.o											\
					WrongCat.o												\
					brain.o													\
																			\

NAME = iDontWantToSetTheWorldOnFire


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $^ $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
