# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 21:09:17 by tkong             #+#    #+#              #
#    Updated: 2023/03/13 05:25:51 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

CC			= cc
CCFLAG		= -Wall -Wextra -Werror -O2
LIB			= $(FT) $(MLX)	\
			  -framework OpenGL -framework AppKit
RM			= rm -f

FT_DIR		= ./ft/
FT_HDR		= $(FT_DIR)ft.h
FT			= $(FT_DIR)libft.a

MLX_DIR		= ./mlx/
MLX_HDR		= $(MLX_DIR)mlx.h
MLX			= $(MLX_DIR)libmlx.a

SRC_DIR		= ./src/
SRC_LST		= main.c		\
			  util.c		\
			  execute.c		\
			  pixel.c		\
			  render.c		\
			  quit.c		\
			  event.c		\
			  iter.c		\
			  screen.c		\
			  zoom.c		\
			  mandelbrot.c	\
			  julia.c		\
			  mandelbar.c	\
			  mlx_extend.c
SRC			= $(addprefix $(SRC_DIR), $(SRC_LST))
INC			= ./src/fractol.h

SRC_B_DIR	= ./src/
SRC_B_LST	= main_bonus.c			\
			  util_bonus.c			\
			  execute_bonus.c		\
			  pixel_bonus.c			\
			  render_bonus.c		\
			  quit_bonus.c			\
			  event_bonus.c			\
			  iter_bonus.c			\
			  screen_bonus.c		\
			  zoom_bonus.c			\
			  mandelbrot_bonus.c	\
			  julia_bonus.c			\
			  mandelbar_bonus.c		\
			  mlx_extend_bonus.c
SRC_B		= $(addprefix $(SRC_B_DIR), $(SRC_B_LST))
INC_B		= ./src/fractol_bonus.h

ifdef B
	SEL = $(SRC_B)
	SELI = $(INC_B)
else
	SEL = $(SRC)
	SELI = $(INC)
endif

$(NAME): $(FT) $(MLX) $(SEL) $(SELI)
	$(CC) $(CCFLAG) $(SEL) $(LIB) -o $(NAME)

$(FT):
	make -sC $(FT_DIR)

$(MLX):
	make -sC $(MLX_DIR)

all: $(NAME)

bonus:
	make B=1 all

clean:
	make -sC $(FT_DIR) clean
	make -sC $(MLX_DIR) clean

fclean: clean
	$(RM) $(FT) $(MLX) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
