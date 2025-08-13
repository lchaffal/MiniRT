SRC = close_window.c find_coordonates.c main.c vector/vector.c
OBJ = $(SRC:.c=.o)

NAME = miniRT

UNAME = $(shell uname)
MAKE = gmake

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lXext -lX11 -lm -lz

LIBFT_DIR = ./libft
LIBFT_FILE = $(LIBFT_DIR)/libft.a

LIBMLX_DIR = ./minilibx
LIBMLX_FILE = $(LIBMLX_DIR)/libmlx_$(UNAME).a

LDFLAGS += -L$(LIBMLX_DIR) -lmlx_$(UNAME) -L$(LIBFT_DIR) -lft

all: $(NAME)

$(LIBFT_FILE):
	$(MAKE) -C $(LIBFT_DIR) all

$(LIBMLX_FILE):
	$(MAKE) -C $(LIBMLX_DIR) all

$(NAME): $(OBJ) $(LIBFT_FILE) $(LIBMLX_FILE)
	cc $(OBJ) $(LDFLAGS) -o $@

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBMLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean
	$(MAKE) -C $(LIBFT_DIR) re
	$(MAKE) -C $(LIBMLX_DIR) re
	$(MAKE) all
