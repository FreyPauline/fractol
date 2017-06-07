# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 15:20:37 by pfrey             #+#    #+#              #
#    Updated: 2017/06/07 17:38:13 by pfrey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Werror -Wextra -O3 -Ofast
SRC = ./srcs/main.c \
	  ./srcs/ft_init_windows.c \
	  ./srcs/ft_init_start_mlx.c \
	  ./srcs/ft_print_head.c \
	  ./srcs/ft_fractal.c \
	  ./srcs/ft_display.c \
	  ./srcs/ft_mouse_hook.c \
	  ./srcs/ft_key.c \
	  ./srcs/ft_esc.c \

# COLORS
C_NO = "\033[00m"
C_OK = "\033[34m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

# DBG MESSAGE
SUCCESS = [ $(C_GOOD)OK$(C_NO) ]
OK = [ $(C_OK)OK$(C_NO) ]

OBJ = $(SRC:.c=.o)
	LFLAGS = -Llibft -lft -framework OpenGL -framework AppKit -Llib-mlx -lmlx

.PHONY : clean fclean re

all: lib-mlx/libmlx.a libft/libft.a $(NAME)

libft/libft.a:
	@make -C libft

lib-mlx/libmlx.a:
	@make -C lib-mlx

$(NAME) : $(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $^ $(LFLAGS)
	@echo $(SUCCESS) "\t\t" "Compiling " $(NAME)

%.o: %.c
	@gcc $^ $(CFLAGS) -c -o $@

clean :
	@rm -f $(OBJ)
	@make clean -C libft
	@make clean -C lib-mlx
	@echo $(OK) "\t\t Cleaning $(NAME)"

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C lib-mlx
	@echo $(OK) "\t\t Delete $(NAME)"

re : fclean all
