NAME = libftprintf.a
NAME_B = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
ARCHIVE = ar -crs
SRCS = ft_putchar.c	\
		ft_putstr.c \
 		ft_putnbr.c \
		ft_putnbr_u.c \
	 	to_hex_lower.c \
		to_hex_upper.c \
		print_ptr.c \
		ft_printf.c \
		ft_strchr.c

SRCS_B = $(wildcard *_bonus.c)
LIBFT = -lft -L libft
	
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: lib $(NAME)

lib:
	cd libft && make

$(NAME): $(OBJS)
	$(ARCHIVE) $(NAME) $(OBJS) libft/*.o

$(OBJS):
	$(CC) $(SRCS) $(CFLAGS)

bonus: lib $(OBJS_B)
	$(ARCHIVE) $(NAME) $(OBJS_B) 

$(OBJS_B):
	$(CC) $(SRCS_B) $(CFLAGS)

clean:
	rm -f *.o libft/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re lib bonus
