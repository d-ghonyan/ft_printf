NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
ARCHIVE = ar -crs
SRCS = $(wildcard *.c)
LIBFT = -lft -L libft
	
OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

lib:
	cd libft && make

$(NAME): $(OBJS)
	$(ARCHIVE) $(NAME) $(OBJS) 

$(OBJS):
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT)

clean:
	rm -f *.o libft/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re lib
