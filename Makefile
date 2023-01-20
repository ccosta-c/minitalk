# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:09:28 by ccosta-c          #+#    #+#              #
#    Updated: 2023/01/19 11:28:07 by ccosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME = minitalk.a
COMPILER = cc
AR = ar -rc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT):
	 @make -C libft
	$(COMPILER) $(CFLAGS) client.c $(LIBFT) -o $(CLIENT)

$(SERVER):
	$(Compiler) $(CFLAGS) server.c $(LIBFT) -o $(SERVER)

clean:
	$(RM) 

fclean: clean
	$(RM)  