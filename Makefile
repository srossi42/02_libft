NAME = libft.a

CC = gcc

CS =	ft_putchar.c \
		ft_putstr.c \
		ft_swap.c \
	 	ft_memset.c \
	 	ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c

OS = $(CS:.c=.o)

HEADDIR = libft.h

CFLAGS = -I$(HEADDIR) -Wall -Wextra -Werror

.PHONY : all
all: $(NAME)

$(NAME): $(OS)
		@ar -rc $(NAME) $(OS)
		@ranlib $(NAME)

.PHONY : clean
clean:
		@rm -f $(OS)

.PHONY : fclean
fclean: clean
		@rm -f $(NAME)

.PHONY : re
re: fclean all
