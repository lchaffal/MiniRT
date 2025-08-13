SRC = close_window.c main.c
OBJ = $(SRC:.c=.o)

NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =
LIBFT = ./libft/
LIBFTFLAGS = -L./libft -l:libft.a
LIBX = ./minilibx-linux/ 
LIBXFLAGS = -L./minilibx-linux -l:libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT) all 
	make -C $(LIBX) all 
	cc -Wall -Werror -Wextra -o $@ $^ $(LIBFTFLAGS) $(LIBXFLAGS) -g

%.o : %.c
	cc -Wall -Werror -Wextra -o $@ -c $< -g

clean :
	make -C $(LIBFT) clean
	make -C $(LIBX) clean
	rm -f $(OBJ)

fclean : clean
	make -C $(LIBFT) fclean
	make -C $(LIBX) clean
	rm -f $(NAME)

re : fclean
	make -C $(LIBFT) re 
	make -C $(LIBX) re 
	make all
