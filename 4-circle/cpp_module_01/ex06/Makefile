# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 03:52:03 by tkong             #+#    #+#              #
#    Updated: 2023/02/12 18:43:01 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter
CPL = c++
OPT = -Wall -Wextra -Werror -std=c++98 -O2 -o $(NAME)
INC = Harl.hpp
SRC = Harl.cpp\
	  main.cpp

$(NAME): $(INC) $(SRC) Makefile
	$(CPL) $(OPT) $(SRC)

all: $(NAME)

clean:

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
