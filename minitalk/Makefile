# COLORS
GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
RESET	= \033[0m

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

SRV		=	server
SRVF	=	$(addprefix $(FOLDER), server.c)

CLI		=	client
CLIF	=	$(addprefix $(FOLDER), client.c)

FOLDER	=	src/
FILES	=	server.c \
			client.c \
			utils.c
SRC 	=	$(addprefix $(FOLDER), $(FILES))
OBJ 	=	$(SRC:.c=.o)

all: $(SERVER) $(CLIENT)
	@$(CC) $(FLAGS) -o $(SRV) $(SRVF)
	@$(CC) $(FLAGS) -o $(CLI) $(CLIF)
	@echo "[$(GREEN)created$(RESET)]: Server & Client executable"

clean:
	@$(RM) $(OBJ)
	@echo "[$(RED)deleted$(RESET)]: *.o files"

fclean: clean
	@$(RM) server
	@$(RM) client
	@echo "[$(RED)deleted$(RESET)]: Server & Client executable"

re: fclean all

.PHONY: all clean fclean re