NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb -lm -lz

SRCDIR = src
BONUSDIR = src_bonus
LIBFTDIR = Libft
MLX = minilibx-linux

MANDATORY_SRCS = $(SRCDIR)/main.c \
                 $(SRCDIR)/execution.c

BONUS_SRCS = $(BONUSDIR)/pipex_bonus.c \
             $(BONUSDIR)/execution_bonus.c \
             $(BONUSDIR)/execution2_bonus.c \
             $(BONUSDIR)/parsing_bonus.c \
             $(BONUSDIR)/ft_perror_bonus.c \
             $(BONUSDIR)/fun_helper_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a
MLX_LIB = $(MLX)/libmlx_Linux.a

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(LIBFT) $(MLX) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LIBFT) -L$(MLX) -lmlx_Linux -lXext -lX11 -o $(NAME)

bonus: $(LIBFT) $(MLX) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -L$(MLX) -lmlx_Linux -lXext -lX11 -o $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(MLX):
	@make -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(BONUSDIR) -I$(LIBFTDIR) -I$(MLX) -O3 -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	@make -C $(LIBFTDIR) clean
	@make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(MLX) clean

re: fclean all
