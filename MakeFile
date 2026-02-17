NAME = pushswap


CC = cc 

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRCS = ft_printf.c \
       ft_putchar.c \
       ft_putstr.c \
       ft_putnbr.c \
       ft_putnbr_unsigned.c \
       ft_puthex.c \
       ft_putptr.c

OBJS = $(SRCS:.c=.o)\\ must not relink

HEADER = pushswap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)	$(OBJS) -O $(NAME)

%.o: %.c
	$(CC)	$(CFLAGS)	-c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
