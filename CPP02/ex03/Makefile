# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 18:31:05 by clorin            #+#    #+#              #
#    Updated: 2021/09/11 18:31:08 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	bsp

CC		= clang++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= srcs/main.cpp srcs/Fixed.cpp srcs/Point.cpp srcs/bsp.cpp

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