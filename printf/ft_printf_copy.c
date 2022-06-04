/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:48:40 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/04 18:09:31 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

t_out *format_flag( t_out *tab, char* arg)
{
	int j;
	int i;
	j = 0;
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
	return(tab);
}

int	ft_format_output	(t_out *tab, char *arg, size_t i) //%jhfjkwhhfkjweh
{
	tab = format_flag(tab, arg);
	while (ft_is_in(arg[i], "cspdiuxX%") == -1 )
		i++;
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
	return (i);
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
	printf("\nprintf: *|%010.7..5s|","ciaociaociao");
			fflush(NULL);
	printf("\nprintf: ****|%10.7s|","ciaociaociao");
		fflush(NULL);
	ft_printf("\nft_printf: *|%.7.8.9.2.3.1.s|","ciaociaociao");//'0' results in undefined behavior with 's' conversion specifier
	printf("\nprintf: ****|%.7.8.9.2.3.1.s|\n","ciaociaociao");//'0' results in undefined behavior with 's' conversion specifier
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
	ft_printf("\nft_printf : %u", 429496724);
	printf("\n***printf : %u", 429445495);
			fflush(NULL);
	ft_printf("\nft_printf : %u", -255460);
	printf("\n***printf : %u", -255460);
			fflush(NULL);
	ft_printf("\nft_printf : %20u", 42947295);
	printf("\n***printf : %20u", 42949295);
			fflush(NULL);
	ft_printf("\nft_printf : %-20.12u", 42945);
	printf("\n***printf : %-20.12u", 42945);
				fflush(NULL);
	ft_printf("\nft_printf: \t|%-28.20u|\n", -1202); //flag '+' results in undefined behavior with 'u' conversion specifier
	printf("\n***printf: \t|%-28.20u|\n", -1202); //flag '+' results in undefined behavior with 'u' conversion specifier
				fflush(NULL);
	ft_printf("\nft_printf: \t|%+-%|\n");
	printf("\n***printf: \t|%-+%|\n");
				fflush(NULL);
	return 0;
}
// ft_printf:      |000000000000000001202|$
// ft_printf:      |    000000000000000001202|$
// printf:         |00000000000000001202|$
// printf:         |        00000000000000001202|$