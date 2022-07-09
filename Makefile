# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 12:24:20 by tkong             #+#    #+#              #
#    Updated: 2022/07/06 12:44:51 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAG		= -Wall -Wextra -Werror
OBJFLAG		= -c
LINKFLAG	= -g
ARCH		= ar
ARCHFLAG	= rcs
SRC			= srcs/ft_putchar.c	\
			  srcs/ft_swap.c	\
			  srcs/ft_putstr.c	\
			  srcs/ft_strlen.c	\
			  srcs/ft_strcmp.c
OBJ			= srcs/ft_putchar.o	\
			  srcs/ft_swap.o	\
			  srcs/ft_putstr.o	\
			  srcs/ft_strlen.o	\
			  srcs/ft_strcmp.o
INC			= includes/ft.h
RM			= rm -f

$(NAME) :	$(OBJ) $(INC)
	$(ARCH) $(ARCHFLAG) $(NAME) $(OBJ) $(INC)

$(BONUS) :	

srcs/ft_putchar.o :
	$(CC) $(CFLAG) $(OBJFLAG) srcs/ft_putchar.c -o srcs/ft_putchar.o

srcs/ft_swap.o :
	$(CC) $(CFLAG) $(OBJFLAG) srcs/ft_swap.c -o srcs/ft_swap.o

srcs/ft_putstr.o :
	$(CC) $(CFLAG) $(OBJFLAG) srcs/ft_putstr.c -o srcs/ft_putstr.o

srcs/ft_strlen.o :
	$(CC) $(CFLAG) $(OBJFLAG) srcs/ft_strlen.c -o srcs/ft_strlen.o

srcs/ft_strcmp.o :
	$(CC) $(CFLAG) $(OBJFLAG) srcs/ft_strcmp.c -o srcs/ft_strcmp.o

re :		fclean all

all :		$(NAME)

bonus :		all $(BONUS)

clean :
	$(RM) $(OBJ)

fclean :	clean
	$(RM) $(NAME)
