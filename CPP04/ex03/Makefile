# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 14:48:19 by clorin            #+#    #+#              #
#    Updated: 2021/09/23 14:48:22 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME 	:= 	materia

CC		:= clang++

CFLAGS	+= -Wall -Wextra -Werror -std=c++98

SRCS_DIR = srcs/

OBJS_DIR = objs/

SRCS	= main.cpp MateriaSource.cpp AMateria.cpp Ice.cpp Character.cpp Cure.cpp

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


