# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-carl <gde-carl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 15:47:29 by gde-carl          #+#    #+#              #
#    Updated: 2023/05/31 04:19:25 by gde-carl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_DIR= ./

SRCS	= ft_isdigit.c ft_memset.c ft_strjoin.c ft_atoi.c ft_strtrim.c ft_isprint.c \
		  ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_itoa.c ft_putendl_fd.c \
		  ft_strlcpy.c ft_tolower.c ft_bzero.c ft_putnbr_fd.c ft_strlen.c \
		  ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c \
		  ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
		  ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c \

BONUS 	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

OBJS 	= ${SRCS:.c=.o}

OBJ_B	= ${BONUS:.c=.o}

CC		= gcc

RM		= rm -f

FLAGS	= -Wall -Wextra -Werror

.c.o:
		@${CC} ${FLAGS} -g -c $< -o $@

$(NAME): $(OBJS)
		@ar rcs ${NAME} ${OBJS}

all: $(NAME)

bonus : ${OBJ_B} 
		@ar rcs ${NAME} ${OBJ_B}

clean:
		@${RM} ${OBJS} ${OBJ_B} 

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY : all bonus clean fclean re
