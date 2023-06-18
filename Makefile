# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-carl <gde-carl@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 18:11:45 by gde-carl          #+#    #+#              #
#    Updated: 2023/06/18 18:13:17 by gde-carl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
CLIENT		= client
SERVER		= server

LIB_D		= libft
LIBFT		= libft/libft.a

SRC_C		= client.c
SRC_S		= server.c
OBJ_S		= server.o
OBJ_C		= client.o
INC 		= minitalk.h

CC 		= gcc
CFLAG 		= -Wall -Wextra -Werror
RM 		= rm -rf
NORMINETTE 	= norminette -R CheckForbiddenSourceHeader
GREEN 		= \e[38;5;118m
YELLOW 		= \e[38;5;226m
RESET 		= \e[0m
_SUCCESS 	= [$(GREEN)SUCCESS$(RESET)]
_INFO 		= [$(YELLOW)INFO$(RESET)]

all: $(LIBFT) $(CLIENT) $(SERVER) guide

$(SERVER): $(OBJ_S) $(INC) $(LIBFT)
	@ $(CC) $(CFLAG) -L$(LIB_D) -lft -o $@ $(OBJ_S) -L$(LIB_D) -lft
	@ printf "$(_SUCCESS) server started.\n"

$(CLIENT): $(OBJ_C) $(INC) $(LIBFT)
	@ $(CC) $(CFLAG) -o $@ $(OBJ_C) -L$(LIB_D) -lft
	@ printf "$(_SUCCESS) client ready.\n"

$(OBJ_S): $(SRC_S) $(INC)
	@ $(CC) $(CFLAG) -c $< -o $@

$(OBJ_C): $(SRC_C) $(INC) $(LIBFT)
	@ $(CC) $(CFLAG) -c $< -o $@

$(LIBFT):
	@ $(MAKE) -C $(LIB_D)
	@ printf "$(_SUCCESS) libft compiled.\n"

clean:
	@ $(MAKE) clean -C $(LIB_D)
	@ $(RM) $(OBJ_C) $(OBJ_S)
	@ printf "$(_INFO) object files deleted.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIB_D)
	@ $(RM) $(CLIENT) $(SERVER)
	@ printf "$(_INFO) client removed.\n"
	@ printf "$(_INFO) server removed.\n"
	@ printf "$(_SUCCESS) all done!\n"

re: fclean all

guide:
	@ printf "$(_INFO) 'make usage' for guide.\n"

usage:
	@ echo "\t\033[96m$ make [usage | all | server | client | clean | fclean | re | norm]\033[96m"
	@ echo "\033[96m\tusage: displays this message\033[96m"
	@ echo "\033[96m\tall: compiles client and server\033[96m"
	@ echo "\033[96m\tserver: compiles server\033[96m"
	@ echo "\033[96m\tclient: compiles client\033[96m"
	@ echo "\033[96m\tclean: remove object files\033[96m"
	@ echo "\033[96m\tfclean: remove object files and programs\033[96m"
	@ echo "\033[96m\tre: fclean and all\033[96m"
	@ echo "\033[0;31m\tnorm to execute order norminette"

norm:
	@ $(NORMINETTE) $(SRC_C) $(SRC_S) $(INC) || true

.PHONY: all clean fclean re
