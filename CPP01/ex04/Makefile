# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 15:18:35 by clorin            #+#    #+#              #
#    Updated: 2021/09/10 15:18:58 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	replace

CC		= clang++

CFLAGS	= -Wall -Wextra -Werror

SRCS	= srcs/main.cpp srcs/Replace.cpp srcs/Ft_string.cpp

OBJS	= $(SRCS:.cpp=.o)

.ccp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all:	${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:		
			@echo "Cleaning: ${OBJS}"
			@rm -rf ${OBJS}

fclean:		clean
			@rm -rf ${NAME}
			@echo "\033[0mdelete "${NAME}"... \033[32mok\033[0m"

re:			fclean all

.phony: all clean fclean re