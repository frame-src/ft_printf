/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:02:32 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/09 20:54:14 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_precision_value( int precision, int len)
{
	if (precision > len)
		return(precision);
	else
		return(len);
}
int print_unsigned_wdt( int zero, int precision, int width, int len, int i)
{
	int z;

	z = 0;
	if( zero > 0 && precision == 0)
	{
		while(i < width - len)
		{
			z+= write(1,"0", 1);
			i++;
		}
	}
	else
	{
		while(i < width - len)
		{
			z+= write(1," ", 1);
			i++;
		}
	}
	return (z);
}

int ft_print_out_unsigned(t_out *tab)
{
	int i;
	int z;
	unsigned int num;
	int precision_value;
	num = va_arg(tab->args, unsigned int);

	i = 0;
	z = 0;
	precision_value = ft_precision_value( tab->dot, how_big(num, 10));
	if(tab->wdt != 0 && tab->wdt - precision_value && tab->dash == 0)
	{
		while(i < tab->wdt - how_big(num,10))
		{
			z+= write(1," ", 1);
			i++;
		}
	}
	i = 0;
	if(tab->dot > 0 && (tab->dot - 1) - how_big( num, 10) > 0 && tab->dash == 0)//  posto x la precisione: se x < L non succede niente. Se x < W
	{
		// if(num > 0 && (tab->sign > 0)) //se c'e' il segno negativo mi serve lo spazio perche' almeno 1 e' preso dal segno di merda di nuovo
		// 	i = 1;
		while(i < (tab->dot - 1) - how_big( num, 10))
		{
			z+= write(1, "0", 1);
			i++;
		}
	}
	// if((tab->sign > 0))
	// 	z += write(1, "+", 1);
	i = 0;
	if(tab->dot > 0 && (tab->dot - 1) - how_big( num, 10) > 0 && tab->dash == 1)
	{
		while(i < (tab->dot -1) - how_big( num, 10))
		{
			z+= write(1, "0", 1);
			i++;
		}
	}
	if(num == 0)
		z+= write( 1, "0", 1);
	else
		z += decimal_to_base(num, "0123456789");
	if(tab->wdt != 0 && tab->wdt - how_big(num, 10) > 0 && tab->wdt - (tab->dot - 1) > 0 && tab->dash == 1)
	{
		while(i < tab->wdt - how_big( num, 10))
		{
			z+= write(1, " ", 1);
			i++;
		}
	}
	return (z);
}