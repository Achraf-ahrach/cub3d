NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
SRCPA = src/parsing
SRCRA = src/raycasting
LIBFT = src/libft/libft.a
MLX = minilibx_opengl/libmlx.a
LIB =  -lmlx -framework OpenGL -framework AppKit #-O3
SRCP = $(wildcard $(SRCPA)/*.c)
SRCR = $(wildcard $(SRCRA)/*.c)


all: $(NAME)

$(NAME): $(SRCP) $(SRCR) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LIB) $(SRCP) $(SRCR) $(LIBFT)  -o $@

$(OBJ):
	mkdir $@

$(LIBFT):
	make all clean -C ./src/libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

push : fclean 
	git add .
	git commit -m "Updated"
	git push

re: fclean  all