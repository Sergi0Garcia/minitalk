# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 10:17:35 by segarcia          #+#    #+#              #
#    Updated: 2022/10/10 10:42:02 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		= server
CLIENT		= client
LIBFT		= ./libft/libft.a
LIBFT_PATH	= ./libft

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(SERVER): $(LIBFT) server.c
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT) client.c
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(CLIENT)

clean :
	@make clean -C $(LIBFT_PATH)
	@$(RM) *.o

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY:	all clean fclean re