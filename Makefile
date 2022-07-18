# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 12:24:20 by tkong             #+#    #+#              #
#    Updated: 2022/07/18 16:18:39 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAG		= -Wall -Wextra -Werror
OBJFLAG		= -c
ARCH		= ar
ARCHFLAG	= rcs
SRC			= ft_atoi.c					\
              ft_bzero.c				\
              ft_calloc.c				\
              ft_isalnum.c				\
              ft_isalpha.c				\
              ft_isascii.c				\
              ft_isdigit.c				\
              ft_isprint.c				\
              ft_itoa.c					\
			  ft_memchr.c				\
			  ft_memcmp.c				\
			  ft_memcpy.c				\
			  ft_memmove.c				\
			  ft_memset.c				\
			  ft_putchar_fd.c			\
			  ft_putendl_fd.c			\
			  ft_putnbr_fd.c			\
			  ft_putstr_fd.c			\
			  ft_split.c				\
			  ft_strchr.c				\
			  ft_strdup.c				\
			  ft_striteri.c				\
			  ft_strjoin.c				\
			  ft_strlcat.c				\
			  ft_strlcpy.c				\
			  ft_strlen.c				\
			  ft_strmapi.c				\
			  ft_strncmp.c				\
			  ft_strnstr.c				\
			  ft_strrchr.c				\
			  ft_strtrim.c				\
			  ft_substr.c				\
			  ft_tolower.c				\
			  ft_toupper.c
SRC_B		= ft_lstadd_back_bonus.c	\
              ft_lstadd_front_bonus.c	\
              ft_lstclear_bonus.c		\
              ft_lstdelone_bonus.c		\
              ft_lstiter_bonus.c		\
			  ft_lstlast_bonus.c		\
			  ft_lstmap_bonus.c			\
			  ft_lstnew_bonus.c			\
			  ft_lstsize_bonus.c
OBJ			= $(SRC:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)
INC			= libft.h
RM			= rm -f

ifdef WITH
	SEL = $(OBJ_B)
else
	SEL = $(OBJ)
endif

%.o :		%.c
	$(CC) $(CFLAG) $(OBJFLAG) $?

$(NAME) :	$(SEL)
	$(ARCH) $(ARCHFLAG) $(NAME) $?

all :		$(NAME)

bonus :
	make WITH=1 all

clean :
	$(RM) $(OBJ) $(OBJ_B)

fclean :	clean
	$(RM) $(NAME)

re :		fclean all

.PHONY :	all bonus clean fclean re
