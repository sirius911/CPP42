# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 08:57:22 by clorin            #+#    #+#              #
#    Updated: 2021/09/09 08:57:26 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= zombie

CC		= clang++

CFLAGS	= -Wall -Wextra -Werror

SRCS	= srcs/main.cpp srcs/Zombie.cpp srcs/ZombieHorde.cpp

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

