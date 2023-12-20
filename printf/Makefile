FLAGS	=	-Wall -Werror -Wextra

NAME	=	 libftprintf.a

HEAD = ft_printf.h

SRCS	=	ft_basic.c \
			ft_putnbr.c \
			ft_printf.c \

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) $(HEAD)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
