# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 13:24:55 by clorin            #+#    #+#              #
#    Updated: 2021/09/04 14:51:56 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone


CC		= clang++

CFLAGS	= -Wall -Wextra -Werror

SRCS	= srcs/megaphone.cpp

OBJS	= $(SRCS:.cpp=.o)

all:	${NAME}

${OBJS}:	${SRCS}
			@echo "Compiling: $<"
			@${CC} ${CFLAGS} -c $< -o $@

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

