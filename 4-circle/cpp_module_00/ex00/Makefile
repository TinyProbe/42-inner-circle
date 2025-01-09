# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 17:43:00 by tkong             #+#    #+#              #
#    Updated: 2023/02/10 19:42:41 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CPL = c++
OPT = -Wall -Wextra -Werror -std=c++98 -O2 -o $(NAME)
SRC = megaphone.cpp

$(NAME): $(SRC) Makefile
	$(CPL) $(OPT) $(SRC)

all: $(NAME)

clean:

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
