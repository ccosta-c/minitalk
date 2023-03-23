# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:09:28 by ccosta-c          #+#    #+#              #
#    Updated: 2023/01/27 13:58:44 by ccosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COLORS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=/
COMPILER = cc
AR = ar -rcs
RM = rm -f

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=
CFLAGS 	= -Wall -Wextra -Werror
MKFLAGS	= --no-print-directory
LIBFT 	= libft/libft.a

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=
NAME 		= minitalk
CLIENT 		= client
SERVER 		= server
MDTYCLTSRC 	= mandatory/client.c
MDTYCLTOBJ 	= $(MDTYCLTSRC:%.c=%.o)
MDTYSVRSRC 	= mandatory/server.c
MDTYSVROBJ 	= $(MDTYSVRSRC:%.c=%.o)
BNSCLTSRC 	= bonus/client_bonus.c
BNSCLTOBJ 	= $(BNSCLTSRC:%.c=%.o)
BNSSVRSRC 	= bonus/server_bonus.c
BNSSVROBJ 	= $(BNSSVRSRC:%.c=%.o)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=

all: $(NAME)

$(NAME): $(MDTYCLTOBJ) $(MDTYSVROBJ)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/libft.a$(RESET)"
	make $(MKFLAGS) -C libft
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)client executable$(RESET)"
	$(COMPILER) $(CFLAGS) $(MDTYCLTOBJ) $(LIBFT) -o $(CLIENT)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)server executable$(RESET)"
	$(COMPILER) $(CFLAGS) $(MDTYSVROBJ) $(LIBFT) -o $(SERVER)
	echo "$(GREEN)Done.$(RESET)"

bonus: $(BNSCLTOBJ) $(BNSSVROBJ)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/libft.a$(RESET)"
	make $(MKFLAGS) -C libft
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)client bonus executable$(RESET)"
	$(COMPILER) $(CFLAGS) $(BNSCLTOBJ) $(LIBFT) -o $(CLIENT)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)server bonus executable$(RESET)"
	$(COMPILER) $(CFLAGS) $(BNSSVROBJ) $(LIBFT) -o $(SERVER)

clean:
	echo "[$(RED) Deleted $(RESET)] $(GREEN)libft/*.o$(RESET)"
	make clean -C libft
	echo "[$(RED) Deleted $(RESET)] $(GREEN)/mandatory/*.o$(RESET)"
	$(RM) $(MDTYCLTOBJ) $(MDTYSVROBJ)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)/bonus/*.o$(RESET)"
	$(RM) $(BNSCLTOBJ) $(BNSSVROBJ)

fclean: clean
	echo "[$(RED) Deleted $(RESET)] $(GREEN)client$(RESET)"
	$(RM) $(CLIENT)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)server$(RESET)"
	$(RM) $(SERVER)

re: fclean all

.SILENT: 
.PHONY: all bonus clean fclean re