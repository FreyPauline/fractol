# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 15:47:17 by pfrey             #+#    #+#              #
#    Updated: 2017/06/07 15:47:19 by pfrey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmlx.a
SRCS= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c

OBJ1=$(SRCS:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: directories $(NAME)

$(NAME): $(OBJ)
			@echo "\033[32m|||------- ✔ Compilation $(NAME) 😎  -------------|||\033[0m"
			@ar -rc $(NAME) $(OBJ)
			@ranlib $(NAME)

%.o:%.c
			@clang $(CFLAGS) -o $@ -c $^ 2> /dev/null
%.o:%.m
			@clang $(CFLAGS) -o $@ -c $^ 2> /dev/null

clean:
		@echo "\033[31m|||------- ❌ Remove files .o $(NAME) ------------|||\033[0m"
			@rm -f $(OBJ) *~

fclean: clean
		@echo "\033[31m|||------- ❌ Remove Libft  $(NAME) --------------|||\033[0m"
			@rm -f $(NAME) $(OBJ) *~

re: fclean all

.PHONY: all clean fclean re run directories cleanlib
