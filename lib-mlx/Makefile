# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrey <pfrey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 15:47:17 by pfrey             #+#    #+#              #
#    Updated: 2017/06/07 17:40:11 by pfrey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmlx.a
SRCS= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c

OBJ1=$(SRCS:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# COLORS
C_NO = "\033[00m"
C_OK = "\033[34m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

# DBG MESSAGE
SUCCESS = [ $(C_GOOD)OK$(C_NO) ]
OK = [ $(C_OK)OK$(C_NO) ]

all: directories $(NAME)

$(NAME): $(OBJ)
			@ar -rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo $(SUCCESS) "\t\t" "Compiling " $(NAME)

%.o:%.c
			@clang $(CFLAGS) -o $@ -c $^ 2> /dev/null
%.o:%.m
			@clang $(CFLAGS) -o $@ -c $^ 2> /dev/null

clean:
		@rm -f $(OBJ) *~
		@echo $(OK) "\t\t Cleaning $(NAME)"

fclean: clean
		@rm -f $(NAME) $(OBJ) *~
		@echo $(OK) "\t\t Delete $(NAME)"

re: fclean all

.PHONY: all clean fclean re run directories cleanlib
