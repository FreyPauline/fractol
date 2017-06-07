NAME = libft.a
CC = gcc
SRC = ft_isalnum.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strlen.c \
	ft_strclen.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memmove.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strjoin_free.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_strsplit_generic.c \
	ft_strctrim.c \
	ft_itoa.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line.c
HEADER = libft.h
FLAG =  -Wall -Werror -Wextra
OPTION = -c -I $(HEADER)
OBJ=$(SRC:.c=.o)

# COLORS
C_NO = "\033[00m"
C_OK = "\033[34m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

# DBG MESSAGE
SUCCESS = [ $(C_GOOD)OK$(C_NO) ]
OK = [ $(C_OK)OK$(C_NO) ]

all: $(NAME)

$(NAME) :
	@$(CC) $(FLAG) $(OPTION) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo $(SUCCESS) "\t\t" "Compiling " $(NAME)

clean:
	@rm -f $(OBJ)
	@echo $(OK) "\t\t Cleaning $(NAME)"

fclean: clean
	@rm -f $(NAME)
	@echo $(OK) "\t\t Delete $(NAME)"

re: fclean all

.PHONY: all clean fclean re
