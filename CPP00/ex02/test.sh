# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 10:17:10 by clorin            #+#    #+#              #
#    Updated: 2021/09/23 13:06:46 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make re
./GlobalBanksters > out
cat out | cut -d "]" -f2 > mine
rm out
cat 19920104_091532.log | cut -d "]" -f2 > true
diff mine true
[[ $? -eq 0 ]] && echo -e "[ \033[32mOK\033[0m ] All good :)" || echo -e "[ \033[31mKO\033[0m ] Test failed :("
rm mine true
make fclean
