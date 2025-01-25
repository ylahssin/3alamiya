NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb

SRCDIR = src
BONUSDIR = src_bonus
LIBFTDIR = Libft

MANDATORY_SRCS = $(SRCDIR)/main.c \
				 $(SRCDIR)/operations.c \
				 $(SRCDIR)/operations_2.c \
                 $(SRCDIR)/helper.c \
                 $(SRCDIR)/parsing.c

BONUS_SRCS = $(BONUSDIR)/checker.c \
             $(BONUSDIR)/operations_bonus.c \
             $(BONUSDIR)/opeeration_bonus_3.c \
             $(BONUSDIR)/operations_2_bonus.c \
             $(BONUSDIR)/parsing_bonus.c \
             $(BONUSDIR)/helper_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)

$(LIBFT):
	@make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(BONUSDIR) -I$(LIBFTDIR) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	@make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus

