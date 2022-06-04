/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:48:40 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/04 15:30:28 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef t_test;

typedef struct t_test{
	
	t_test *content;
	void *previous;
	void *next;
}		s_test;

typedef struct s_out
{
	va_list	args;		//arguments (content, ...);
	int	wdt;			//width
	int	prc;			//precision
	int	zero;			//zero padding
	int	dot;			//.
	int	dash;			//-
	int	tl;				//total_length (return value)
	int	sign;			//pos or neg number
	int	is_zero;		//is number zero
	int	percent;		//%
	int	space;			//space flag ' '
}t_out;

t_out *ft_init_tab(t_out *ptr)
{
	ptr->wdt = 0;
	ptr->prc = 0;
	ptr->zero = 0;
	ptr->dot = 0;
	ptr->dash = 0;
	ptr->sign = 0;
	ptr->is_zero = 0;
	ptr->percent = 0;
	ptr->space = 0;
//	ptr->tl = 0;
	return (ptr);
}

int how_big_to( size_t n, int i)
{
	int len;
	
	len = 0;
	while(n > 0)
	{	
		n = n/i;
		len++;
	}
	return (len);
}

int decimal_to_base(unsigned n, char *base)
{
	int i;
	size_t b;

	i = 0;
	while(base[i])
		i++;
	if (n>0)
	{
		decimal_to_base(n/i, base);
		write(1, &base[n%i], 1);
	}
	return (how_big_to(n, i));
}

int ft_is_in(const char c, char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(c == str[i])
			return i;
		i++;
	}
	return (-1);
}

int	ft_strlen(char *c)
{
	int i = 0;
	while(c[i]!= '\0')
		i++;
	return i;
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_print_out_char(t_out *tab)
{
	int w;
	char c = va_arg(tab->args, int);
	w = write(1,&c,1);
	return w;
}

int	ft_print_out_str(t_out *tab)
{
	int		w;
	int		k;
	char	*c;
	int		precision_len;
	
	w = 0;
	k = 0;
	c = va_arg(tab->args, char *);
	if( c == NULL)
		c = "(null)";
	if(tab->dash == 0)
	{
		if(tab->wdt != 0 && (tab->wdt - ft_strlen(c) > 0 || tab->wdt - (tab->dot -1) > 0) && tab->dash == 0) // THE CONDITION IN THE MIDDLE with II is cause of this: ft_printf("#WTF|%3.2s|WTF\n", "DOOM")
		{
			if (tab->dot > 0)
			{
				if (tab->dot -1 >= ft_strlen(c))
					precision_len = ft_strlen(c);
				else
					precision_len = tab->dot -1;
			}
			if(tab->zero == 1 && tab->dot >= 0 && tab->space == 0)
			{
				k = 0;
				while(k < (tab->wdt - precision_len))
					k += write(1, "0", 1);
			}
			else
			{
				k = 0;
				while(k < (tab->wdt - precision_len))
					k += write(1, " ", 1);
			}
		}
		if(tab->dot != 0)
		{
			while(w < (tab->dot -1) && c[w] != '\0')
				w += write(1, &c[w], 1);
			if (tab->dot < 0)
			{
				tab->dot = -1*(tab->dot);
				while(w < (tab->dot -1) && c[w] != '\0')
				w += write(1, " ", 1);
			}
		}
		else
			w = write(1, c, ft_strlen(c));
	}
	if(tab->dash > 0)
	{
		if(tab->dot != 0)
		{
			while(w < (tab->dot -1) && c[w] != '\0')
				w += write(1, &c[w], 1);
			if (tab->dot < 0) //----------negative precision JUST PRINT SPACE
			{
				tab->dot = - 1 * (tab->dot);
				while(w < (tab->dot -1) && c[w] != '\0')
					w += write(1, " ", 1);
				tab->dot = - 1 * (tab->dot);
			}
		}
		if(tab->wdt != 0 && (tab->wdt - ft_strlen(c) > 0 || tab->wdt - (tab->dot - 1)> 0) && tab->dot > 0)// THE CONDITION IN THE MIDDLE with II is cause of this: ft_printf("#WTF|%3.2s|WTF\n", "DOOM")
		{
			if (tab->dot > 0)
			{
				if (tab->dot -1 >= ft_strlen(c))
					precision_len = ft_strlen(c);
				else
					precision_len = tab->dot -1;
			}
			if(tab->zero == 1 && tab->dot >= 0 && tab->space == 0)
			{
				k = 0;
				while(k < (tab->wdt - precision_len))
					k += write(1, "0", 1);
			}
			else
			{
				k = 0;
				while(k < (tab->wdt - precision_len))
					k += write(1, " ", 1);
			}
		}
	}
	return (k + w); //is returning 11
}

int	ft_print_out_ptr(t_out *tab)
{
	char *tmp;
	char	*c;
	char *mailbox;
	int i;
	c = va_arg(tab->args, void *);
	mailbox = &c;
	while(mailbox[i])
	{
		printf("mailbox:\t %x  %d\n", mailbox[i], i);
		i++;
	}//write(1, &mailbox, sizeof(mailbox));
}

int	ft_print_out_nbr(t_out *tab)
{
	long int num;
	long int b;
	int sign;
	int i;
	size_t z;
	
	num = va_arg(tab->args, int);
	b = num;
	sign = 1;
	if( num < 0)
		{
			num = -1 * num;
			sign = -1;
		}
	i = 0;
	if(tab->wdt != 0 && tab->wdt - how_big_to(num, 10) > 0 && tab->wdt - (tab->dot - 1) > 0 && tab->dash == 0)
	{
		if((tab->sign > 0) || sign < 0) //se c'e' il segno negativo mi serve lo spazio perche' almeno 1 e' preso dal segno di merda
			i = 1;
		while(i < tab->wdt - how_big_to(num,10))//scrivi finche' ne hai lo spazio - la grandezza della stringa
		{
			z+= write(1," ", 1);
			i++;
		}
	}
	i = 0;
	if(tab->dot > 0 && (tab->dot - 1) - how_big_to( num, 10) > 0 && tab->dash == 0)//  posto x la precisione: se x < L non succede niente. Se x < W
	{
		if((tab->sign > 0) || sign < 0) //se c'e' il segno negativo mi serve lo spazio perche' almeno 1 e' preso dal segno di merda di nuovo
			i = 1;
		while(i < (tab->dot - 1) - how_big_to( num, 10))
		{
			z+= write(1, "0", 1);
			i++;
		}
	}
	if(num > 0 && (tab->sign > 0))
		z += write(1, "+", 1);
	if(sign < 0)
		z += write(1, "-", 1);
	i = 0;
	if(tab->dot > 0 && (tab->dot - 1) - how_big_to( num, 10) > 0 && tab->dash == 1)
	{
		// if((tab->sign > 0) || sign < 0) //se c'e' il segno negativo mi serve lo spazio perche' almeno 1 e' preso dal segno di merda di nuovo
		// 	i = 1;
		while(i < (tab->dot -1) - how_big_to( num, 10))
		{
			z+= write(1, "0", 1);
			i++;
		}
	}
	decimal_to_base(num, "0123456789");
	// if(tab->wdt != 0 && tab->wdt - how_big_to(num, 10) > 0 && tab->wdt - (tab->dot - 1) > 0 && tab->dash == 1)
	// {
	// 	if((tab->sign > 0) || sign < 0) // if flag + is up, or num < 0;
	// 		i = 1;
	// 	while(i < tab->wdt - how_big_to( num, 10))
	// 	{
	// 		z+= write(1, " ", 1);
	// 		i++;
	// 		if(i == how_big_to(num, 10) ||)
	// 	}
	// }
	i = 0;
	if(tab->wdt != 0 && tab->wdt - how_big_to(num, 10) > 0 && tab->wdt - (tab->dot - 1) > 0 && tab->dash == 1)
	{
		// if((tab->sign > 0) || sign < 0) // if flag + is up, or num < 0;
		// 	i = 1;
		if(tab->dot -1 - how_big_to(num, 10) >= 0)
		{
			while(i <= tab->wdt - tab->dot -1) // widht - num lenght buuuut. THE PRECISION!!!
			{
				z+= write(1, " ", 1);
				i++;
			}
		}
		if(tab->dot -1 - how_big_to(num, 10) < 0)
		{
			while(i <= tab->wdt - how_big_to(num, 10)) // widht - num lenght buuuut. THE PRECISION!!!
			{
				z+= write(1, " ", 1);
				i++;
			}
		}
	}


	return (1);
}
int ft_print_out_unsigned(t_out *tab)
{
	int i;
	int z;
	unsigned int num;
	num = va_arg(tab->args, unsigned int);

	i = 0;
	if(tab->wdt != 0 && tab->wdt - how_big_to(num, 10) > 0 && tab->wdt - (tab->dot - 1) > 0 && tab->dash == 0)
	{
		// if((tab->sign > 0)) //se c'e' il segno mi serve lo spazio perche' almeno 1 e' preso dal segno di merda
		// 	i = 1;
		while(i < tab->wdt - how_big_to(num,10))//- how_big_to( num, 10)? ATTENZIONE
		{
			z+= write(1," ", 1);
			i++;
		}
	}
	i = 0;
	if(tab->dot > 0 && (tab->dot - 1) - how_big_to( num, 10) > 0 && tab->dash == 0)//  posto x la precisione: se x < L non succede niente. Se x < W
	{
		// if(num > 0 && (tab->sign > 0)) //se c'e' il segno negativo mi serve lo spazio perche' almeno 1 e' preso dal segno di merda di nuovo
		// 	i = 1;
		while(i < (tab->dot - 1) - how_big_to( num, 10))
		{
			z+= write(1, "0", 1);
			i++;
		}
	}
	// if((tab->sign > 0))
	// 	z += write(1, "+", 1);
	i = 0;
	if(tab->dot > 0 && (tab->dot - 1) - how_big_to( num, 10) > 0 && tab->dash == 1)
	{
		while(i < (tab->dot -1) - how_big_to( num, 10))
		{
			z+= write(1, "0", 1);
			i++;
		}
	}
	decimal_to_base(num, "0123456789");
	if(tab->wdt != 0 && tab->wdt - how_big_to(num, 10) > 0 && tab->wdt - (tab->dot - 1) > 0 && tab->dash == 1)
	{
		while(i < tab->wdt - how_big_to( num, 10))
		{
			z+= write(1, " ", 1);
			i++;
		}
	}


	return (1);
}

int ft_print_out_hex(t_out *tab, char *prefix)
{
	
	int i;
	int z;
	unsigned int num;
	num = va_arg(tab->args, unsigned int);

	i = 0;
	if(tab->wdt != 0 && tab->wdt - how_big_to(num, 10) > 0 && tab->wdt - (tab->dot - 1) > 0 && tab->dash == 0)
	{
		// if((tab->sign > 0)) //se c'e' il segno mi serve lo spazio perche' almeno 1 e' preso dal segno di merda
		// 	i = 1;
		while(i < tab->wdt - how_big_to(num,10))//- how_big_to( num, 10)? ATTENZIONE
		{
			z+= write(1," ", 1);
			i++;
		}
	}
	i = 0;
	if(tab->dot > 0 && (tab->dot - 1) - how_big_to( num, 10) > 0 && tab->dash == 0)//  posto x la precisione: se x < L non succede niente. Se x < W
	{
		// if(num > 0 && (tab->sign > 0)) //se c'e' il segno negativo mi serve lo spazio perche' almeno 1 e' preso dal segno di merda di nuovo
		// 	i = 1;
		while(i < (tab->dot - 1) - how_big_to( num, 10))
		{
			z+= write(1, "0", 1);
			i++;
		}
	}
	// if((tab->sign > 0))
	// 	z += write(1, "+", 1);
	i = 0;
	if(tab->dot > 0 && (tab->dot - 1) - how_big_to( num, 10) > 0 && tab->dash == 1)
	{
		while(i < (tab->dot -1) - how_big_to( num, 10))
		{
			z+= write(1, "0", 1);
			i++;
		}
	}
	decimal_to_base(num, prefix);
	if(tab->wdt != 0 && tab->wdt - how_big_to(num, 10) > 0 && tab->wdt - (tab->dot - 1) > 0 && tab->dash == 1)
	{
		while(i < tab->wdt - how_big_to( num, 10))
		{
			z+= write(1, " ", 1);
			i++;
		}
	}
	return (z);
}

int	ft_print_out_percent(t_out *tab)
{
	int w;
	char c = va_arg(tab->args, int);
	w = write(1,"%",1);
	return w;
}


int	ft_get_precision( char *num, int i) //arg[i] = '.'
{
	int	len;
	// int sign;
	// sign = 1;
	// if(num[i] == '-')
	// {
	// 	sign = -1;
	// 	i++;
	// }
	len = 0;
	while(ft_isdigit((int)num[i]) != 0)
	{
		len = (len * 10) + ((num[i]) - '0');
		i++;
	}

	return (len + 1);//(sign*(len + 1));
}
int ft_get_wdt(char *num, int i)
{
	int len;
	len = 0;
	while (ft_isdigit((int)num[i]) != 0)
	{
		len = (len * 10) + ((num[i]) - '0');
		i++;
	}
	//printf("\nlen wdt = %d\n", len);
	return (len);
}
int	ft_format_output	(t_out *tab, char *arg, size_t i) //%jhfjkwhhfkjweh
{
	int j = 0;
	while (ft_is_in(arg[i], "cspdiuxX%") == -1 )
	{
		if(arg[i] == '0' && tab->wdt == 0)
			tab->zero = 1;
		else if(arg[i] == '-')
			tab->dash = 1;
		else if(arg[i] == '.') //   .958;
			tab->dot = ft_get_precision(arg, i + 1); //i numeri per l'indice i li conto comunque perche' i++ alla fine va' +1 finche' becca numeri e non entra i wdt per tan->dot == 0;
		else if(arg[i] == '+')
			tab->sign = 1;
		else if(arg[i] == ' ')
			tab->space = 1;
		else if(arg[i] == '%')
			tab->percent = 1;
		else if(ft_isdigit(arg[i])) //&& (tab->dot == 0) && tab->wdt == 0) //%7.434d
			tab->wdt = ft_get_wdt(arg,i);
		i++;
		j++;
	}
	if(ft_is_in(arg[i], "cspdiuxX%") != -1)
	{
		if(arg[i] == 'c')
			tab->tl += ft_print_out_char(tab);
		else if (arg[i] == 's')
			tab->tl += ft_print_out_str(tab);
		else if (arg[i] == 'p') //manage only - and widht.
			tab->tl += ft_print_out_ptr(tab);
		else if (arg[i] == 'd' || arg[i] == 'i')
			tab->tl += ft_print_out_nbr(tab);
		else if (arg[i] == 'u')
			tab->tl += ft_print_out_unsigned(tab);
		else if (arg[i] == 'x')
			tab->tl += ft_print_out_hex(tab, "0123456789abcdef");
		else if (arg[i] == 'X')
			tab->tl += ft_print_out_hex(tab, "0123456789ABCDEF");
		else if (arg[i] == '%')
			tab->tl += ft_print_out_percent(tab);
	}
	ft_init_tab(tab); //after i do the stuff initialize the tab again or get fucked because after the % u can get another % and you are not calling again printf but arte simply keeping reading
	return (1 + j);
}
// "....content... %s ... %0.10x ... %-0.10"
int ft_printf(/*const*/ char *content, ...)
{
	int i;
	int ret;
	t_out *tab;

	tab = (t_out *)malloc(sizeof(t_out));
	if (!tab)
		return (-1);
	tab = ft_init_tab(tab);
	tab->tl = 0;
	va_start(tab->args, content); //ft_printf(content, ...)
	i = 0;
	ret = 0;
	while (content[i] != '\0') // while the string exists
	{
		if (content[i] == '%') // %#2164.12123
			i += ft_format_output(tab, content, i + 1); // evaluate the output
		else
			ret += write(1, &content[i], 1); //print what you read
		i++;
		//printf("i:%d content[i]=%c \n",i, content[i]);
	}
	va_end(tab->args);
	ret += tab->tl;
	free (tab);
	return (ret);
}



int main (void)
{
	//ft_printf("let me see if you work ***: %c \t %0222.-12s\n", 'V', "hello world");
	//char *s = "dipolo";
	ft_printf("\n//STRING ////////////////////\n");
	ft_printf("\nft_printf: *|%010.-7..5s|","ciaociaociao");
	printf("\nprintf: *|%010.-7..5s|","ciaociaociao");
			fflush(NULL);
	printf("\nprintf: ****|%010.-7s|","ciaociaociao");
		fflush(NULL);
	ft_printf("\nft_printf: *|%0.-7.8.9.2.3.1.s|","ciaociaociao");
	printf("\nprintf: ****|%0.-7.8.9.2.3.1.s|\n","ciaociaociao");
			fflush(NULL);
	// printf("\n   printf:|%010.-7-s|","ciaociaociao");
	// printf("\ntest%0#-+ 18.15stest", "4294967295");
	// ft_printf("\ntest%0#-+ 18.15stest\n", "4294967295");
	//printf("%p",printf("\n printf %p\n", NULL)); 
	//printf("%c\n", *s);// Is looking for the dereferentiation of a null, wich is supposed to be in 0x0 so i seg_fault
	//ft_printf("\nft_printf:%p\n", "HLlloa fAenn21af..?fkW2+_dakf");
	// printf("%d",printf("%p\n", s));
	// 	fflush(NULL);
	//ft_printf("%d\n", 466487);
	ft_printf("\n//INTEGER /////////////////\n");
	ft_printf("\nft_printf: \t|%3.22d|", 50002);
	printf("\n***printf: \t|%3.22d|", 50002);
			fflush(NULL);
	ft_printf("\nft_printf: \t|%-18.20d|", 1202);
	printf("\n***printf: \t|%-18.20d|", 1202);
			fflush(NULL);
	ft_printf("\nft_printf: \t|%28.20d|", -1202);
	printf("\nprintf: \t|%28.20d|", -1202);
			fflush(NULL);
	printf("\nprintf: \t|%-28.20d|", 1202);
			fflush(NULL);
	

	// unsigned
	ft_printf("\n//UNSIGNED /////////////////\n");
	ft_printf("\nft_printf : %u", 42949672454545495);
	printf("\n***printf : %u", 42949672454545495);
			fflush(NULL);
	ft_printf("\nft_printf : %u", -2554600000);
	printf("\n***printf : %u", -2554600000);
			fflush(NULL);
	ft_printf("\nft_printf : %20u", 4294967295);
	printf("\n***printf : %20u", 4294967295);
			fflush(NULL);
	ft_printf("\nft_printf : %-20.12u", 42945);
	printf("\n***printf : %-20.12u", 42945);
				fflush(NULL);
	ft_printf("\nft_printf: \t|%+-28.20u|\n", -1202);
	printf("\n***printf: \t|%-+28.20u|\n", -1202);
				fflush(NULL);
	ft_printf("\nft_printf: \t|%+-%|\n", -1202);
	printf("\n***printf: \t|%-+%|\n", -1202);
				fflush(NULL);
	return 0;
}
// ft_printf:      |000000000000000001202|$
// ft_printf:      |    000000000000000001202|$
// printf:         |00000000000000001202|$
// printf:         |        00000000000000001202|$