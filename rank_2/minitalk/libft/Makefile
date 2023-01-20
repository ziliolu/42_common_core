NAME = libft.a 
all: $(NAME)

$(NAME):
	make -C libft	
	make -C get_next_line
	make -C printf	

clean:
	make clean -C libft	
	make clean -C get_next_line
	make clean -C printf	

fclean: 
	make fclean -C libft	
	make fclean -C get_next_line
	make fclean -C printf	

re: fclean all