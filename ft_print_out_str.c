/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:03 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/06 10:37:30 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int set_precision_len(int len_str, int precision_value)
{
	if (precision_value >= len_str || precision_value < 0)
		return (len_str);
	else
		return (precision_value);

}

int print_out_wdt(int precision_len, int wdt, int zero)
{
	int k;

	k = 0;
	if((wdt > 0) && (wdt - precision_len > 0))
	{
		if(zero > 0)
		{
			k = 0;
			while(k < (wdt - precision_len))
				k += write(1, "0", 1);
		}
		else
		{
			while(k < (wdt - precision_len))
			k += write(1, " ", 1);
		}
	}
	return (k);
}

int	ft_print_out_str(t_out *tab)
{
	int		w;
	int		k;
	char	*c;
	int		precision_len;
	
	w = 0;
	c = va_arg(tab->args, char *);
	if( c == NULL)
		c = "(null)";
	precision_len = set_precision_len(ft_strlen(c), tab->dot -1);
	if(tab->dash == 0)
		k = print_out_wdt (precision_len, tab->wdt, tab->zero);
	while(w < precision_len)
	{
		w += write(1, &c[w], 1);
	}
	if(tab->dash > 0)
		k = print_out_wdt (precision_len, tab->wdt, 0);
	return (k + w);
}