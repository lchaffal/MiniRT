SRC = close_window.c main.c
OBJ = $(SRC:.c=.o)

NAME = miniRT

UNAME = $(shell uname)
MAKE = gmake

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/local/lib

LIBFT_DIR = ./libft
LIBFT_FILE = $(LIBFT_DIR)/libft.a
LDFLAGS += -L$(LIBFT_DIR)

LIBMLX_DIR = ./minilibx
LIBMLX_FILE = $(LIBMLX_DIR)/libmlx_$(UNAME).a
LDFLAGS += -L$(LIBMLX_DIR)

LDFLAGS += -lft -lmlx_$(UNAME) -lXext -lX11 -lm -lz



all: $(NAME)



$(LIBFT_FILE):
	$(MAKE) -C $(LIBFT_DIR) all

$(LIBMLX_FILE):
	$(MAKE) -C $(LIBMLX_DIR) all



$(NAME): $(OBJ) $(LIBFT_FILE) $(LIBMLX_FILE)
	cc $(LDFLAGS) $(OBJ) -o $@

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
