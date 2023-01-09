# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:09:28 by ccosta-c          #+#    #+#              #
#    Updated: 2023/01/07 16:31:06 by ccosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
Compiler = cc
AR = ar -rc
RM = rm -f
CFlags = -Wall -Wextra -Werror
PRINTF = printf/libftprintf.a
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT):
	 @make -C printf
	$(Compiler) $(CFlags) client.c $(PRINTF) -o $(CLIENT)

$(SERVER):
	$(Compiler) $(CFlags) server.c $(PRINTF) -o $(SERVER)
