# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raghonya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 14:24:11 by raghonya          #+#    #+#              #
#    Updated: 2023/03/19 17:40:12 by raghonya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CFLAGS	=	-Wall -Wextra -Werror -g

LIB		=	libft/libft.a

PLIB	=	printf/libftprintf.a

MLX		=	minilibx-linux

LFLAGS	=	-I./minilibx-linux -lmlx -lXext -lX11

OBJDIR	=	obj

ifeq ($(shell uname -s), Darwin)
	MLX = minilibx
	LFLAGS = -I./minilibx -lm -lmlx -framework OpenGL -framework AppKit
endif

FILES	=	so_long.c \
			parsing.c \
			parsing_norm.c \
			directions.c \
			for_directions.c \
			put_images.c \
			animation.c

OBJ		=	$(FILES:%.c=$(OBJDIR)/%.o)

all: $(OBJDIR) run_lib run_printf $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c Makefile so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L./$(MLX) $(LFLAGS) -o $(NAME) $(PLIB) $(LIB)

run_lib:
	@make -C libft

run_printf:
	@make -C printf

run_MLX:
	@make -C $(MLX)

clean:
	@rm -f *.o
	@make clean -C libft
	@make clean -C printf
	@make clean -C $(MLX)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C printf

re: fclean all

.PHONY: run_lib run_printf run_MLX all clean fclean re
