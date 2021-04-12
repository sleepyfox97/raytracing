NAME	:= miniRT
GCC		:= gcc
CFLAFS	:= -wall -wextra -werror
INCLUDE:= 

SRCS	:=

OBJS	:= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(GCC) $(CFLAFS) -c $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c $(INCLUDE)
	$(GCC) -c (CFLAFS) -o $@ $<

.PHONY: all clean fclean re bonus