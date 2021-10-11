# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 13:24:55 by clorin            #+#    #+#              #
#    Updated: 2021/09/04 16:54:25 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= GlobalBanksters


CC		= clang++

CFLAGS	= -Wall -Wextra -Werror

SRCS	= tests.cpp Account.cpp

OBJS	= $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

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

