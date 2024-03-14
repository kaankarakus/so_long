SRCS = ft_dectohex.c   ft_printf.c     ft_putchar.c    ft_putnbr.c     ft_putstr.c     ft_putunbr.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(SRCS) $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re