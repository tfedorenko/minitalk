# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 14:49:04 by tfedoren          #+#    #+#              #
#    Updated: 2022/05/23 19:09:46 by tfedoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME1 = client
all: server client

server: server.c
	gcc -o $(NAME) -Wall -Werror -Wextra $(NAME).c Libft/ft_printf.c \
		Libft/ft_putnbr.c \
		Libft/ft_puthexadecimalnbr.c \
		Libft/ft_putchar.c \
		Libft/ft_putstr.c \
		Libft/ft_putunsignednbr.c \
		Libft/ft_putvoidptr.c \
		Libft/ft_strlen.c
	
client: client.c 
	gcc -o $(NAME1) -Wall -Werror -Wextra $(NAME1).c Libft/ft_printf.c \
		Libft/ft_putnbr.c \
		Libft/ft_puthexadecimalnbr.c \
		Libft/ft_putchar.c \
		Libft/ft_putstr.c \
		Libft/ft_putunsignednbr.c \
		Libft/ft_putvoidptr.c \
		Libft/ft_strlen.c \
		Libft/ft_atoi.c

clean:
	rm -rf server client

fclean: clean
	rm -rf server client

re: fclean all

.PHONY: all clean fclean re bonus
