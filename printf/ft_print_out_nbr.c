/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:01:18 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/04 17:19:16 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_out_nbr(t_out *tab)
{
	long int num;
	long int b;
	int sign;
	int i;
	size_t z;
	
	z = 0;
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