# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 12:49:46 by segarcia          #+#    #+#              #
#    Updated: 2022/10/06 11:35:29 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi.c 			\
					ft_isdigit.c 		\
					ft_itoa.c 			\
					ft_putchar_fd.c 	\
					ft_putstr_fd.c  	\
					ft_strlen.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
