NAME = fillit

CC = gcc -g

CS =	ft_valid.c \
		ft_read.c \
		ft_printlist_tetri.c \
		ft_fillit.c \
		ft_piece_reset.c \
		ft_test.c

OS = $(CS:.c=.o)

HEADDIR = fillit.h

CFLAGS = -I$(HEADDIR) -Wall -Wextra -Werror

.PHONY : all
all: $(NAME)

$(NAME): $(OS) 
		make -C libft/
		$(CC) $(CFLAGS) -c $(CS)
		@$(CC) $(OS) -o $(NAME) -L ./libft -lft

.PHONY : clean
clean:
		make clean -C libft
		@rm -f $(OS)

.PHONY : fclean
fclean: clean
		make fclean -C libft
		@rm -f $(NAME)

.PHONY : re
re: fclean all
