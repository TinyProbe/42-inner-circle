# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:35:02 by tkong             #+#    #+#              #
#    Updated: 2022/09/22 17:06:47 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
NAME1		= server
NAME2		= client
BONUS		= minitalk_bonus
BONUS1		= server_bonus
BONUS2		= client_bonus
CC			= cc
CFLAG		= -Wall -Wextra -Werror
LEAK		= -g3 -fsanitize=address
SRC_MS		= server.c			\
			  handler.c			\

SRC_MC		= client.c			\
			  send.c			\

SRC_BS		= server_bonus.c	\
			  handler_bonus.c	\
			  send_bonus.c		\

SRC_BC		= client_bonus.c	\
			  handler_bonus.c	\
			  send_bonus.c		\

LIB			= libft/libft.a
RM			= rm -f

$(NAME) :	$(NAME1) $(NAME2)

$(NAME1) :	$(LIB) $(SRC_MS)
	$(CC) $(CFLAG) $(SRC_MS) $(LIB) -o $(NAME1)

$(NAME2) :	$(LIB) $(SRC_MC)
	$(CC) $(CFLAG) $(SRC_MC) $(LIB) -o $(NAME2)

$(BONUS) :	$(BONUS1) $(BONUS2)

$(BONUS1) :	$(LIB) $(SRC_BS)
	$(CC) $(CFLAG) $(SRC_BS) $(LIB) -o $(BONUS1)

$(BONUS2) :	$(LIB) $(SRC_BC)
	$(CC) $(CFLAG) $(SRC_BC) $(LIB) -o $(BONUS2)

$(LIB) :
	make -C ./libft B=1 all

all :		$(NAME)

bonus :		$(BONUS)

clean :
	make -C ./libft clean

fclean :	clean
	$(RM) $(LIB) $(NAME1) $(NAME2) $(BONUS1) $(BONUS2)
	$(RM) -r *.dSYM

re :		fclean all

.PHONY :	all bonus clean fclean re
