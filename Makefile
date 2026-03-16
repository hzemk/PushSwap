NAME	= pushswap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

AR		= ar rcs
RM		= rm -f

SRCS	=adaptive.c\
	 complex_algo.c\
	 ft_putnb.c\
	 init_stack.c\
	 medium.c\
	 pick_algo.c\
	 simple.c\
	 util.c\
	 bench.c\
	 disorder.c\
	 helpers2.c\
	 main.c\
	 medutil.c\
	 printf.c\
	 revrot.c\
	 split.c\
	 check_flag.c\
	 helpers.c\
	 parsing.c\
	 push.c\
	 rotate.c\
	 swap.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
