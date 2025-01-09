# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 12:24:20 by tkong             #+#    #+#              #
#    Updated: 2022/08/12 17:41:45 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAG		= -Wall -Wextra -Werror
OBJFLAG		= -c
AR			= ar
ARFLAG		= rcs
SRC_M		= ft_printf.c			\
			  ft_vfprintf.c			\
			  ft_validation.c		\
			  ft_vali_combi.c		\
			  ft_form.c				\
			  ft_iswhat.c			\
			  ft_iswhat2.c			\
			  ft_setarg.c			\
			  ft_conversion.c		\
			  ft_apply.c			\
			  ft_utils.c			\

SRC_B		= ft_printf_bonus.c		\
			  ft_vfprintf_bonus.c	\
			  ft_validation_bonus.c	\
			  ft_vali_combi_bonus.c	\
			  ft_form_bonus.c		\
			  ft_iswhat_bonus.c		\
			  ft_iswhat2_bonus.c	\
			  ft_setarg_bonus.c		\
			  ft_conversion_bonus.c	\
			  ft_apply_bonus.c		\
			  ft_utils_bonus.c		\

OBJ_M		= $(SRC_M:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)
CUR_M		= ft_printf.o
CUR_B		= ft_printf_bonus.o
LIB			= ./libft/libft.a
RM			= rm -f

ifdef B
	SEL		= $(OBJ_B)
	UNSEL	= $(OBJ_M)
	CUR		= $(CUR_B)
else
	SEL		= $(OBJ_M)
	UNSEL	= $(OBJ_B)
	CUR		= $(CUR_M)
endif

%.o :		%.c
	$(CC) $(CFLAG) $(OBJFLAG) $?

$(NAME) :	$(LIB) $(SEL)
ifeq (, $(wildcard $(CUR)))
	$(RM) $(UNSEL)
	$(AR) $(ARFLAG) $(NAME) $(SEL)
endif

$(LIB) :
ifeq (, $(wildcard $(CUR)))
	make -C ./libft all
	mv $(LIB) $(NAME)
endif

all :		$(NAME)

bonus :
	make B=1 all

clean :
	make -C ./libft clean
	$(RM) $(OBJ_M) $(OBJ_B)

fclean :	clean
	$(RM) $(LIB) $(NAME)

re :
ifneq (, $(wildcard $(CUR_B)))
	make fclean
	make -C ./libft bonus
	mv $(LIB) $(NAME)
	$(CC) $(CFLAG) $(OBJFLAG) $(SRC_B)
	$(AR) $(ARFLAG) $(NAME) $(OBJ_B)
else
	make fclean
	make -C ./libft all
	mv $(LIB) $(NAME)
	$(CC) $(CFLAG) $(OBJFLAG) $(SRC_M)
	$(AR) $(ARFLAG) $(NAME) $(OBJ_M)
endif

.PHONY :	all bonus clean fclean re
