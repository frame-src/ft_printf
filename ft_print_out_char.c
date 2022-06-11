/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:54 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/11 15:25:36 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_out_char(t_out *tab)
{
	int w;
	char c; 
	
	w = 0;
	c = va_arg(tab->args, int);
	if(tab->wdt > 0 && tab->dash == 0)
	{
		if(tab->zero > 0) 
		{	
			while(w < (tab->wdt) -1)
				w += write(1, "0", 1);
		}
		else
		{
			while(w < (tab->wdt) -1)
				w += write(1, " ", 1);
		}
	}
	
	w += write(1,&c,1);
	
	if(tab->wdt > 0 && tab->dash > 0)
	{
		while(w - 1 < (tab->wdt - 1))
		w += write(1, " ", 1);
	}
	return w;
}
