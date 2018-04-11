NAME = ../libftprintf.a

SRCS =	ft_swap.c \
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
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstaddtail.c \
		ft_lstaddafter.c \
		ft_printlist.c \
		ft_lstlen.c \
		ft_lstelempos.c \
		ft_lstmodify_cont.c \
		ft_itoa_base_ll.c \
		ft_itoa_base_ull.c \
		ft_appendchar.c \
		ft_strrev.c \
		ft_max_int.c \
		ft_min_int.c \
		ft_val_abs.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $@ $^
		@ranlib $@
		@echo "Construction Librairie"

%.o: %.c
		@gcc $(FLAGS) -o $@ -c $<

.PHONY : clean
clean:
		@rm -rf $(OBJ)

.PHONY : fclean
fclean: clean
		@rm -rf $(NAME)

.PHONY : re
re: fclean all
