# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 19:57:47 by clorin            #+#    #+#              #
#    Updated: 2021/09/19 19:57:52 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= 	claptrap

CC		:= clang++

CFLAGS	+= -Wall -Wextra -Werror -std=c++98

SRCS	= srcs/main.cpp srcs/ClapTrap.cpp

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
