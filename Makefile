NAME = cub3D
CC = gcc
CFLAGZ = -Wall -Wextra -Werror -lpthread
SRCS = 	src/main.c

MLX_DIR = minilibx-linux
MLX_LIB = libmlx.a

LIBFT = libft.a
LIBFTDIR = libft

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGZ) -g -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(MLX_DIR)/$(MLX_LIB) $(LIBFTDIR)/$(LIBFT)
	$(CC) $(CFLAGZ) -o $(NAME) $(OBJS) -L$(MLX_DIR) -L$(LIBFTDIR) -l:$(LIBFT) -lmlx -lXext -lx11 -lm

$(MLX_DIR)/$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIBFTDIR)/$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS) 
	rm -f $(OBJSBON)

fclean: clean
	rm -f $(NAME) $(B_NAME)
	
re: fclean all