/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:54 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/07 15:27:51 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int print_out_wdt(int precision_len, int wdt, int zero)
// {
// 	int k;

// 	k = 0;
// 	if((wdt > 0) && (wdt - precision_len > 0))
// 	{
// 		if(zero > 0)
// 		{
// 			k = 0;
// 			while(k < (wdt - precision_len))
// 				k += write(1, "0", 1);
// 		}
// 		else
// 		{
// 			while(k < (wdt - precision_len))
// 			k += write(1, " ", 1);
// 		}
// 
// 	return (k);
// }

int	ft_print_out_char(t_out *tab)
{
	int w;
	char c; 
	
	w = 0;
	c = va_arg(tab->args, int);
	if(tab->wdt > 0&& tab->dash == 0)
	{
		if(tab->zero > 0) 
		{	
			while(w < (tab->wdt))
				w += write(1, "0", 1);
		}
		else
		{
			while(w < (tab->wdt))
				w += write(1, " ", 1);
		}
	}
	w += write(1,&c,1);
	if(tab->wdt > 0 && tab->dash > 0)
	{
		while(w < (tab->wdt))
		w += write(1, " ", 1);
	}
	return w;
}
