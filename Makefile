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

FLAGS = -Wall -Wextra -Werror -g

CLIENT_SRCS = client.c mt_putstr.c mt_putchar.c mt_atoi.c

SERVER_SRCS = server.c mt_atoi.c mt_putnbr.c mt_putstr.c mt_putchar.c mt_itoa.c mt_strdup.c mt_strlen.c

CLIENT_OBJ = ${CLIENT_SRCS:.c=.o}
SERVER_OBJ = ${SERVER_SRCS:.c=.o}

all: $(CLIENT) $(NAME)

$(CLIENT):
		@gcc $(FLAGS) $(CLIENT_SRCS) -c
		@gcc $(CLIENT_OBJ) -o $(CLIENT)

$(NAME):
		@gcc $(SERVER_SRCS) -c
		@gcc $(SERVER_OBJ) -o $(NAME)

clean:
	@rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@rm -rf $(CLIENT) $(NAME)

re: fclean all

.PHOMY: clean fclean re