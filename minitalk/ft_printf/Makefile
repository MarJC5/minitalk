# COLORS
GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
RESET	= \033[0m

LIBFT		= 	../libft
LIBNAME		= 	libft.a
NAME 		= 	libftprintf.a
CFLAGS		= 	-Wall -Werror -Wextra -c
CC			= 	gcc
RM			= 	rm -f
AR			= 	ar -rcs
FILES		= 	ft_printf.c \
				ft_printf_char.c \
				ft_printf_str.c \
				ft_printf_ptr.c \
				ft_printf_hex.c \
				ft_printf_int.c \
				ft_printf_dun.c \
				ft_printf_utils.c
OBJ			= 	$(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBFT) 
	@cp $(LIBFT)/$(LIBNAME) $(NAME)
	@$(CC) $(CFLAGS) $(FILES)
	@$(AR) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test tclean valgrind