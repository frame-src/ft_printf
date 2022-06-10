/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:03:29 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/09 20:54:27 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int precision_value( int len, int precision)
{
	if(precision - len > 0)
		return (precision);
	else
		return(len);
}
static int manage_wdt( int precision, int len, int wdt, int zero)
{
	int prc;
	int z;

	z = 0;
	prc = precision_value(len, precision); 
	while(z < wdt - prc)
		if( zero > 0 && precision < 0)
			z+= write( 1, "0", 1);
		else
			z+= write( 1, " ", 1);
	return (z);
}
static int manage_prc( int precision, int len)
{
	int z;
	z = 0;
	
	while(z < precision - len)
		z+= write( 1, "0", 1);
	return (z);
}

int ft_print_out_hex(t_out *tab, char *base, char * prefix)
{
	
	int i;
	int z;     
	unsigned int num;
	num = va_arg(tab->args, unsigned int); 

	i = 0;
	z = 0;
	if(tab->wdt != 0 && tab->dash == 0)
		z += manage_wdt(tab->dot - 1, how_big(num, 16), tab->wdt, tab->zero);
	if(tab->dot > 0 && tab->dash == 0)
		z += manage_prc(tab->dot - 1, how_big( num, 16));
	if(tab->dot > 0 && tab->dash == 1)
		z += manage_prc(tab->dot - 1, how_big( num, 16));
	if(tab->prf > 0 && num != 0)
		z += write(1, prefix, ft_strlen(prefix));
	if(num == 0)
		z+= write( 1, "0", 1);
	else
		z += decimal_to_base(num, base);
	if(tab->wdt != 0 && tab->dash == 1)
		z += manage_wdt(tab->dot - 1, how_big(num, 16), tab->wdt, 0);
	return (z);
}