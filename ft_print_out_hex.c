/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:03:29 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/11 18:03:32 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int precision_value( int precision, int len, unsigned int num)
{
	if (precision > len)
		return (precision);
	else if (precision == 0 && num == 0)
		return (0);
	else
		return (len);
	
}
static int manage_wdt( int precision, int len, int wdt, int zero, unsigned int num)
{
	int prc;
	int z;

	z = 0;
	prc = precision_value(precision, len, num);
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
		z += manage_wdt(tab->dot - 1, how_big(num, 16), tab->wdt, tab->zero, num);
	if(tab->dot > 0 && tab->dash == 0)
		z += manage_prc(tab->dot - 1, how_big( num, 16));
	if(tab->dot > 0 && tab->dash == 1)
		z += manage_prc(tab->dot - 1, how_big( num, 16));
	if(tab->prf > 0 && num != 0)
		z += write(1, prefix, ft_strlen(prefix));
	if(num == 0 && tab->dot -1 != 0)
		z += write( 1, "0", 1);
	if(num != 0)
		z += decimal_to_base(num, base);
	if(tab->wdt != 0 && tab->dash == 1)
		z += manage_wdt(tab->dot - 1, how_big(num, 16), tab->wdt, 0, num);
	return (z);
}