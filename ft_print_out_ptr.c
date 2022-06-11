/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:31 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/12 01:15:08 by frmessin         ###   ########.fr       */
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
static int manage_wdt( int precision, int len, int wdt)
{
	int prc;
	int z;

	z = 0;
	prc = precision_value( len, precision);
	while(z < wdt - (prc + (int)ft_strlen("0x")))
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

int	ft_print_out_ptr(t_out *tab, char *base, char * prefix)
{
	
	int				z;
	unsigned long	num;

	num = va_arg(tab->args, unsigned long); 
	z = 0;
	if (tab->wdt != 0 && tab->dash == 0)
		z += manage_wdt(tab->dot - 1, how_big(num, 16), tab->wdt);
	if (tab->dot > 0 && tab->dash == 0)
		z += manage_prc( tab->dot - 1, how_big( num, 16));
	if (tab->dot > 0 && tab->dash == 1)
		z += manage_prc( tab->dot - 1, how_big( num, 16));
	z += write(1, prefix, ft_strlen(prefix));
	if (num == 0)
		z += write( 1, "0", 1);
	else
		z += decimal_to_base(num, base);
	if (tab->wdt != 0 && tab->dash == 1)
		z += manage_wdt(tab->dot - 1, how_big(num, 16), tab->wdt);
	return (z);
}