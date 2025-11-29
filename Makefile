SRC =	source/main.c \
		\
		source/parsing/parsing.c source/parsing/parsing_real.c source/parsing/parsing_noreal.c source/parsing/parsing_file.c \
		\
		source/engine/ft/ft_atod.c source/engine/ft/ft_isalpha.c source/engine/ft/ft_bzero.c source/engine/ft/ft_isdigit.c source/engine/ft/ft_isspace.c source/engine/ft/ft_putstr_fd.c source/engine/ft/ft_strlen.c source/engine/ft/ft_capalpha.c \
		\
		source/engine/utils.c source/engine/compute.c source/engine/find_coordinates.c source/engine/vector.c source/engine/vector_infos.c source/engine/loading.c \
		\
		source/alloc/alloc.c source/alloc/alloc_real.c source/alloc/alloc_noreal.c source/alloc/alloc_autre.c \
		source/intersection/intersection.c source/intersection/intersection_autre.c source/intersection/intersection_real.c source/intersection/addon/cylinder.c source/intersection/addon/sphere.c \
		source/move/move.c source/move/move_real.c source/move/move_noreal.c source/move/move_autre.c \
		source/normal/normal.c source/normal/normal_real.c source/normal/normal_autre.c \
		\
		source/config/config.c
SRC_DEFAULT = source/engine/limit_default.c
SRC_BONUS = source/engine/limit_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_DEFAULT = $(SRC_DEFAULT:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = miniRT
NAME_BONUS = miniRT_bonus

UNAME = $(shell uname)
MAKE = gmake

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -flto
LDFLAGS = -flto

LIBMLX_DIR = ./library/minilibx
LIBMLX_FILE = $(LIBMLX_DIR)/libmlx_$(UNAME).a
CFLAGS += -I$(LIBMLX_DIR)
LDFLAGS += -L$(LIBMLX_DIR) -lmlx_$(UNAME)

LDFLAGS += -lXext -lX11 -lm -lz

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBMLX_FILE):
	$(MAKE) -C $(LIBMLX_DIR) all

$(NAME): $(OBJ) $(OBJ_DEFAULT) $(LIBMLX_FILE)
	cc $(OBJ) $(OBJ_DEFAULT) $(LDFLAGS) -o $@

$(NAME_BONUS): $(OBJ) $(OBJ_BONUS) $(LIBMLX_FILE)
	cc $(OBJ) $(OBJ_BONUS) $(LDFLAGS) -o $@

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBMLX_DIR) clean
	rm -f $(OBJ)
	rm -f $(OBJ_DEFAULT)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean
	$(MAKE) -C $(LIBMLX_DIR) re
	$(MAKE) all

.PHONY: all bonus clean fclean re
