# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpicoli- < lpicoli-@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:19:38 by lpicoli-          #+#    #+#              #
#    Updated: 2022/12/10 18:48:33 by lpicoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	./ft_filter_format.c	\
		./ft_hexlen.c			\
		./ft_printf.c			\
		./ft_putchar.c			\
		./ft_puthexa.c			\
		./ft_putnbr.c			\
		./ft_putstr.c			\
		./ft_strlen.c			\
		./ft_putptr.c			\
		./ft_put_unsigned.c		\
		./ft_count_digits.c		\


OBJ = $(SRC:.c=.o);
HEADER = ft_printf.h
CC = cc -Wall -Wextra -Werror

%.o: %.c ${HEADER}
		${CC} -I. -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJ} 
			ar rcs	${NAME} ${OBJ}	 

clean:                                                                                                                                                                                                             
		rm -rf $(OBJ) $(OBJ_BONUS)                                                                                                                                                                                             
                                                                                                                                                                                                                   
fclean: clean                                                                                                                                                                                                      
		rm -rf $(NAME) 


re: fclean all                                                                                                                                                                                                     
                  