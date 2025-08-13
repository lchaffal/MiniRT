SRC = close_window.c main.c
OBJ = $(SRC:.c=.o)

NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =

LIBFT = ./libft/
LIBFTFLAGS = -L$(LIBFT) -lft

LIBMLX = ./minilibx/
LIBMLX_FILE = ./minilibx/libmlx_Linux.a

LIBXFLAGS = -L$(LIBMLX) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)


$(LIBMLX_FILE):
	make -C $(LIBX) all


$(NAME): $(OBJ) $(LIBMLX_FILE)
	make -C $(LIBFT) all
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
