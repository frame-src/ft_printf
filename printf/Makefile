NAME = libft.a

SRCS=	ft_printf_utils.c\
		ft_print_out_char.c\
		ft_print_out_str.c\
		ft_print_out_ptr.c\
		ft_print_out_nbr.c\
		ft_print_out_hex.c\
		ft_print_out_percent.c\
		ft_print_out_unsigned.c\
		ft_printf_copy.c\

OBJS=$(SRCS:.c=.o)

CC = cc
CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : $(OBJS)
	ar rc $(NAME) $(OBJ)
	
%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re