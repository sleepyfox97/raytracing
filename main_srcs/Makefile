NAME	:= miniRT
GCC		:= gcc
CFLAGFS	:= -wall -wextra -werror
INCLUDE := miniRT.h

SRCS := main.c
SRCS += read_rtfile1.c read_rtfile2.c read_rtfile3.c read_rtfile4.c read_rtfile5.c
SRCS += libft1.c libft2.c libft3.c
SRCS += ft_vector_utli1.c ft_vector_utli2.c

TSRC := input_test.c

OBJS := $(SRCS:.c=.o)
TOBJ := $(TSRC:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:fclean all

test: $(NAME) $(TOBJ)
	ar -rcs $(NAME) $(TOBJ)

%.o: %.c $(INCLUDE)
	$(GCC) -c $(CFLAGS) -o $@ $<