# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-carl <gde-carl@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 17:21:39 by gde-carl          #+#    #+#              #
#    Updated: 2023/05/27 17:21:43 by gde-carl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 	=
CLIENT	= client
SERVER	= server

PRINTF	= ft_printf/ft_printf.a
P_DIR	= ft_printf

SRC_C	= client.c
SRC_S	= server.c
OBJ_S	= server.o
OBJ_C	= client.o
INC	= minitalk.h

CC	= gcc
CFLAG	= -Wall -Wextra -Werror
RM	= rm -rf

GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(PRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS) $(PRINTF) -o $@ $(OBJ_S)
	@printf "$(_SUCCESS) server started.\n"
$(CLIENT): $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS) $(PRINTF) -o $@ $(OBJ_C)
	@printf "$(_SUCCESS) client ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	@ $(MAKE) -C $(P_DIR)

clean:
	@ $(MAKE) clean -C $(P_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)
	@printf "$(_INFO) object files deleted.\n"

fclean: clean
	@ $(MAKE) fclean -C $(P_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re
