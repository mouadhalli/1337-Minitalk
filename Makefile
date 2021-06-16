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

CLIENT_SRCS = client.c
CLIENT_OBJ = client.o

SERVER_SRCS = server.c
SERVER_OBJ = server.o

all: $(CLIENT) $(NAME)

$(CLIENT):
		@gcc $(CLIENT_SRCS) -c
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