# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 02:00:46 by tkong             #+#    #+#              #
#    Updated: 2023/02/12 02:01:13 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
CPL = c++
OPT = -Wall -Wextra -Werror -std=c++98 -O2 -o $(NAME)
INC = 
SRC = main.cpp

$(NAME): $(INC) $(SRC) Makefile
	$(CPL) $(OPT) $(SRC)

all: $(NAME)

clean:

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
