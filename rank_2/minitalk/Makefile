NAME = minitalk.a
SERVER = server
CLIENT = client

SERVER_SRC = ./src/server.c
CLIENT_SRC = ./src/client.c
SERVER_BONUS_SRC = ./src/server_bonus.c 
CLIENT_BONUS_SRC = ./src/client_bonus.c

OBJ_DIR = ./obj
HEADERS = ./includes
PRINTF_DIR = ./libft/printf
LIBFT_DIR = ./libft
PRINTF_NAME = $(PRINTF_DIR)/libftprintf.a

SERVER_FILES = server.c 
CLIENT_FILES = client.c

#SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_FILES:.c=.o))
#CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f
 
all: $(NAME) 

$(PRINTF_NAME):
	make all -C $(LIBFT_DIR)

$(NAME): $(PRINTF_NAME)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(PRINTF_NAME) -o server
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(PRINTF_NAME) -o client 

bonus: $(PRINTF_NAME) 
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) $(PRINTF_NAME) -o server_bonus
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) $(PRINTF_NAME) -o client_bonus 

clean: 
	make clean -C $(LIBFT_DIR)

fclean: clean 
	make fclean -C $(LIBFT_DIR)
	$(RM) client server client_bonus server_bonus
	
re: fclean all