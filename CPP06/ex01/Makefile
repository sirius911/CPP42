# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 12:50:02 by clorin            #+#    #+#              #
#    Updated: 2021/10/05 12:50:05 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= serialize 	

CC		:= clang++

CFLAGS	+= -Wall -Wextra -Werror -std=c++98

SRCS_DIR = srcs/

OBJS_DIR = objs/

SRCS	= main.cpp Data.cpp

OBJS	= $(SRCS:.cpp=.o)

OBJS	:= ${addprefix ${OBJS_DIR}, ${OBJS}}

${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp
		mkdir -p ${@D}
		$(CC) $(FLAGS) -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:		
			@echo "Cleaning: ${OBJS}"
			@rm -rf ${OBJS_DIR}

fclean:		clean
			@rm -rf ${NAME}
			@echo "\033[0mdelete "${NAME}"... \033[32mok\033[0m"

re:			fclean all

.phony: all clean fclean re

