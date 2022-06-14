MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

NAME = libftprintf.a

SRCS=	ft_printf_utils.c\
		ft_print_out_char.c\
		ft_print_out_str.c\
		ft_print_out_ptr.c\
		ft_print_out_nbr.c\
		ft_print_out_hex.c\
		ft_print_out_percent.c\
		ft_print_out_unsigned.c\
		ft_printf.c\
		ft_printf_calc.c\

BSRCS=	ft_printf_utils_bonus.c\
		ft_print_out_char_bonus.c\
		ft_print_out_str_bonus.c\
		ft_print_out_ptr_bonus.c\
		ft_print_out_nbr_bonus.c\
		ft_print_out_hex_bonus.c\
		ft_print_out_percent_bonus.c\
		ft_print_out_unsigned_bonus.c\
		ft_printf_bonus.c\
		ft_printf_calc_bonus.c\

OBJS=$(SRCS:.c=.o)
BOBJS=$(BSRCS:.c=.o)


CC = cc
CFLAG = -Wall -Wextra -Werror

all: $(NAME)

${BOBJS}: ${BSRCS}
	@$(CC) $(CFLAG) -c -o

bonus:	${NAME}
	@ar rcs $(NAME) $(BOBJS)
	

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAG) -c $^ -o $@

exe:
	@make re
	@cc $(NAME) main.c -g -o print 
	@./print

clean:
	@rm -f $(OBJS)
	@rm -f $(BOBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re