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


OBJ = $(SRC:.c=.o)
CC = cc 
HEADERS = ../../includes
CFLAGS = -Wall -Wextra -Werror -I $(HEADERS)

all: $(NAME)

$(NAME):	$(OBJ)
			ar rcs	$(NAME) $(OBJ)	 

clean:                                                                                                                                                                                                             
		rm -rf $(OBJ) $(OBJ_BONUS)                                                                                                                                                                                             
                                                                                                                                                                                                                   
fclean: clean                                                                                                                                                                                                      
		rm -rf $(NAME) 


re: fclean all                                                                                                                                                                                                     
                  