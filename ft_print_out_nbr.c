/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:01:18 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/08 15:38:04 by frmessin         ###   ########.fr       */
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

int print_nbr_wdt( int zero, int precision, int width, int len, int i)
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

int print_out_sign( int sign, int plus_flag, int space)
{
	int i;

	i = 0;
	if(sign > 0 && (plus_flag > 0 || space > 0 ))
	{
		if( space == 0)
			i = write(1, "+", 1);
		else
			i = write(1, " ", 1);
	}
	if(sign < 0)
		i = write(1, "-", 1);
	return (i);
}

int	ft_print_out_nbr( t_out *tab)
{
	long long int num;
	int sign;
	int i;
	size_t z;
	int p;
	
	z = 0;
	
	num = va_arg(tab->args, int);
	sign = 1;
	if( num < 0)
		{
			num = - 1 * num;
			sign = -1;
		}
	i = 0;
	if(tab->sign > 0 || sign == -1)
		i = 1;
	p = ft_precision_value(tab->dot -1, how_big( num, 10)); 
	if(tab->wdt != 0 && tab->wdt - p > 0 && tab->dash == 0)
		z += print_nbr_wdt(tab->zero, tab->dot, tab->wdt, p, i);
	z += print_out_sign(sign, tab->sign, tab->space);
	i = 0;
	while(i < (tab->dot - 1) - how_big( num, 10))
	{
		z+= write(1, "0", 1);
		i++;
	}
	z += decimal_to_base(num, "0123456789");
	i = 0;
	if(tab->dot == 0 && num == 0)
	{
		z += write(1, "0", 1);
		i = 1;
	}
	if(tab->wdt != 0 && tab->wdt - how_big(num, 10) > 0 && tab->wdt - (tab->dot - 1) > 0 && tab->dash == 1)
	{
		if(tab->sign > 0 || sign == -1)
			i = 1;
		z += print_nbr_wdt(tab->zero, tab->dot, tab->wdt, p, i);
	}
	return (z);
}