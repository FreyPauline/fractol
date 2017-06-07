# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 15:20:37 by pfrey             #+#    #+#              #
#    Updated: 2017/06/07 17:24:24 by pfrey            ###   ########.fr        #
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
	@echo "\033[31m|||------- ✔ Creating $(NAME) executable ---------|||\033[0m"

%.o: %.c
	@gcc $^ $(CFLAGS) -c -o $@

clean :
	@echo "\033[31m|||------- ❌ Removing Object Files $(NAME) -------|||\033[0m"
	@rm -f $(OBJ)
	@make clean -C libft
	@make clean -C lib-mlx

fclean : clean
	@echo "\033[31m|||------- ❌ Removing $(NAME) --------------------|||\033[0m"
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C lib-mlx

re : fclean all
