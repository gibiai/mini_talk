# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 17:21:39 by gde-carl          #+#    #+#              #
#    Updated: 2023/05/28 21:11:39 by gde-carl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	= client
SERVER	= server

LIB_D	= libft
LIBFT	= libft/libft.a
P_DIR	= ft_printf
PRINTF	= ft_printf/libftprintf.a

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

all: $(LIBFT) $(PRINTF) $(CLIENT) $(SERVER) usage

$(SERVER): $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFT) $(PRINTF) -o $@ $(OBJ_S)
	@printf "$(_SUCCESS) server started.\n"	

$(CLIENT): $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFT) $(PRINTF) -o $@ $(OBJ_C)
	@printf "$(_SUCCESS) client ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@ $(MAKE) -C $(LIB_D)

$(PRINTF):
	@ $(MAKE) -C $(P_DIR)

clean:
	@ $(MAKE) clean -C $(LIB_D); $(MAKE) clean -C $(P_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)
	@printf "$(_INFO) object files deleted.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIB_D) ; $(MAKE) fclean -C $(P_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"
	@printf "$(_SUCCESS) all done!\n"

re: fclean all

usage:
	@echo "\033[96mUsage: make [usage | all | server | client | clean | fclean | re]\033[96m"
	@echo
	@echo "\033[96m\tusage: displays this message\033[96m"
	@echo "\033[96m\tall: compiles client and server\033[96m"
	@echo "\033[96m\tserver: compiles server\033[96m"
	@echo "\033[96m\tclient: compiles client\033[96m"
	@echo "\033[96m\tclean: remove object files\033[96m"
	@echo "\033[96m\tfclean: remove object files and programs\033[96m"
	@echo "\033[96m\tre: fclean and all\033[96m"
	@echo "\t\033[1m\033[95mq and enter to exit the program\033[1m\033[95m"

.PHONY: all clean fclean re
