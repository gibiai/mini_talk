# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 17:12:18 by gde-carl          #+#    #+#              #
#    Updated: 2023/05/28 18:41:42 by gde-carl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./ft_printf.c ./ft_putchar.c ./ft_putstr.c ./ft_puthexa.c ./ft_putnbr.c \
		./ft_putptr.c ./ft_putunsigned.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	@${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
	@${RM} $(OBJS)

fclean: clean
	@${RM} $(NAME)

re: fclean all
