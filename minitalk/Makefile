# COLORS
GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
RESET	= \033[0m

CC		=	cc
FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

FOLDER	=	src/
FILES	=	server.c \
			client.c

LIBFT	= ./libft/libft.a
PRINFT	= ./ft_printf/libftprintf.a

UTILS	= 	$(addprefix $(FOLDER), utils.c)

SRV		=	server
SRVF	=	$(addprefix $(FOLDER), server.c)

CLI		=	client
CLIF	=	$(addprefix $(FOLDER), client.c)

SRC 	=	$(addprefix $(FOLDER), $(FILES))
OBJ 	=	$(SRC:.c=.o)

all: $(SERVER) $(CLIENT)
	@$(MAKE) -C ./ft_printf
	@$(CC) $(FLAGS) $(LIBFT) $(PRINFT) $(SRVF) -o $(SRV)
	@$(CC) $(FLAGS) $(LIBFT) $(PRINFT) $(CLIF) -o $(CLI)
	@echo "[$(GREEN)created$(RESET)]: libft.a, libftprintf.a, server & slient"

clean:
	@$(MAKE) -C ./ft_printf clean
	@$(MAKE) -C ./libft clean
	@$(RM) $(OBJ)
	@echo "[$(RED)deleted$(RESET)]: *.o files"

fclean: clean
	@$(MAKE) -C ./ft_printf fclean
	@$(MAKE) -C ./libft fclean
	@$(RM) server
	@$(RM) client
	@echo "[$(RED)deleted$(RESET)]: libft.a, libftprintf.a, server & slient"

re: fclean all

.PHONY: all clean fclean re