
NAME			=	libftprintf.a

SRCS			=	./sources/ft_printf.c		\
					./sources/ft_parsing.c		\
					./sources/ft_output.c		\
					./sources/ft_evaluation.c	\
					./sources/ft_alignment.c

LIBFT			=	./libft/libft.a
LIBFT_PATH		=	libft/

OBJS			=	$(SRCS:.c=.o)
HEAD			=	./includes/ft_printf.h
LIBFT_OBJS		=	$(LIBFT_PATH)*.o
LIBFTMAKE		=	$(MAKE) -C $(LIBFT_PATH)

CFLAGS			=	-Wall -Wextra -Werror -c
CC				=	gcc
RM				=	rm -f
AR				=	ar -rcs

all:				$(NAME)

.c.o: 				$(HEAD)
					$(CC) $(CFLAGS) $< -o $@

$(NAME):			$(OBJS) make
					$(AR) $(NAME) $(OBJS) $(LIBFT_OBJS)

make:
					$(LIBFTMAKE)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJS)

fclean: 			clean
					$(RM) $(NAME) $(LIBFT)

re:         		fclean all
.PHONY:				all clean fclean re