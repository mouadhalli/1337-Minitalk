# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhalli <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 15:20:57 by mhalli            #+#    #+#              #
#    Updated: 2021/06/15 15:20:59 by mhalli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
CLIENT = client

FLAGS = -Wall -Wextra -Werror

CLIENT_SRC = client.c mt_putstr.c mt_putchar.c mt_atoi.c mt_utils.c

CLIENT_BONUS_SRC = bonus_src/client_bonus.c bonus_src/mt_putstr_bonus.c bonus_src/mt_putchar_bonus.c bonus_src/mt_atoi_bonus.c bonus_src/mt_utils_bonus.c

SERVER_SRC = server.c mt_atoi.c mt_putstr.c mt_putchar.c mt_itoa.c mt_strdup.c mt_strlen.c mt_bzero.c mt_utils.c

SERVER_BONUS_SRC = bonus_src/server_bonus.c bonus_src/mt_atoi_bonus.c bonus_src/mt_putstr_bonus.c bonus_src/mt_putchar_bonus.c \
			bonus_src/mt_itoa_bonus.c bonus_src/mt_strdup_bonus.c bonus_src/mt_strlen_bonus.c bonus_src/mt_bzero_bonus.c bonus_src/mt_utils_bonus.c

CLIENT_OBJ = ${CLIENT_SRC:.c=.o}
CLIENT_BONUS_OBJ = ${CLIENT_BONUS_SRC:.c=.o}

SERVER_OBJ = ${SERVER_SRC:.c=.o}
SERVER_BONUS_OBJ = ${SERVER_BONUS_SRC:.c=.o}

all: server client

$(NAME):
		@gcc $(FLAGS) $(SERVER_SRC) -o $(NAME)

$(CLIENT):
		@gcc $(FLAGS) $(CLIENT_SRC) -o $(CLIENT)

bonus:
	@gcc $(FLAGS) $(SERVER_BONUS_SRC) -o server
	@gcc $(FLAGS) $(CLIENT_BONUS_SRC) -o client

clean:
	@rm -rf $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean: clean
	@rm -rf server client

re: fclean all

.PHOMY: clean fclean re all bonus