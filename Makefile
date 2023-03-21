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

#Variables

NAME = minitalk.a
COMPILER = cc
AR = ar -rc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
CLIENT = client
SERVER = server
MDTYCLTSRC = mandatory/client.c
MDTYCLTOBJ = $(MDTYCLTSRC:%.c=%.o)
MDTYSVRSRC = mandatory/server.c
MDTYSVROBJ = $(MDTYSVRSRC:%.c=%.o)
BNSCLTSRC = bonus/client_bonus.c
BNSCLTOBJ = $(BNSCLTSRC:%.c=%.o)
BNSSVRSRC = bonus/server_bonus.c
BNSSVROBJ = $(BNSSVRSRC:%.c=%.o)

all: $(NAME)

$(LIBFT):
	make all -C libft

$(NAME): $(MDTYCLTOBJ) $(MDTYSVROBJ) $(LIBFT)
	$(COMPILER) $(CFLAGS) $(MDTYCLTOBJ) $(LIBFT) -o $(CLIENT)
	$(COMPILER) $(CFLAGS) $(MDTYSVROBJ) $(LIBFT) -o $(SERVER)

bonus: $(BNSCLTOBJ) $(BNSSVROBJ)
	$(COMPILER) $(CFLAGS) $(BNSCLTOBJ) $(LIBFT) -o $(CLIENT)
	$(COMPILER) $(CFLAGS) $(BNSSVROBJ) $(LIBFT) -o $(SERVER)

clean:
	make clean -C libft
	$(RM) $(MDTYCLTOBJ) $(MDTYSVROBJ)
	$(RM) $(BNSCLTOBJ) $(BNSSVROBJ)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re