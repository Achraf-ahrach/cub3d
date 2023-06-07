NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRCF = src
LIBFT = src/libft/libft.a
LIB =  -lmlx -framework OpenGL -framework AppKit 
SRC = $(wildcard $(SRCF)/*.c)

#print:
#@echo $(SRC)

all: $(NAME)

$(NAME):$(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB) $(SRC) $(LIBFT)  -o $@

$(OBJ):
	mkdir $@

$(LIBFT):
	make all clean -C ./src/libft

fcleanlib:
	make fclean -C./src/libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

push : fclean 
	git add .
	git commit -m "Updated"
	git push

re: fclean  all