# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 04:34:34 by tkong             #+#    #+#              #
#    Updated: 2023/02/14 22:19:31 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
CPL = c++
OPT = -Wall -Wextra -Werror -Wshadow -std=c++98 -O2 -o $(NAME)
INC = ClapTrap.hpp\
	  ScavTrap.hpp\
	  FragTrap.hpp\
	  DiamondTrap.hpp
SRC = ClapTrap.cpp\
	  ScavTrap.cpp\
	  FragTrap.cpp\
	  DiamondTrap.cpp\
	  main.cpp

$(NAME): $(INC) $(SRC) Makefile
	$(CPL) $(OPT) $(SRC)

all: $(NAME)

clean:

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
