NAME = libft.a

CC = gcc

CS =	main.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_swap.c \
		ft_strcmp.c \
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
		ft_strstr.c 
	
OS = $(CS:.c=.o)
HEADDIR = libft.h
CFLAGS = -I$(HEADDIR) -Wall -Wextra -Werror

.PHONY : all
all: $(NAME)

$(NAME):
		@$(CC) $(FLAGS) -c $(CS)
		@$(CC) $(FLAGS) $(OS) -o $(NAME)


.PHONY : clean
clean:
		@rm -f $(OS)

.PHONY : fclean
fclean: clean
		@rm -f $(NAME)

.PHONY : re
re: fclean all
