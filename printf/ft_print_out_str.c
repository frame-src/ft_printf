/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:03 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/05 20:31:39 by frmessin         ###   ########.fr       */
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

int	ft_print_out_str(t_out *tab)
{
	int		w;
	int		k;
	char	*c;
	int		precision_len;
	
	w = 0;
	k = 0;
	c = va_arg(tab->args, char *);
	if( c == NULL)
		c = "(null)";
	precision_len = set_precision_len(ft_strlen(c), tab->dot -1);
	if(tab->dash == 0)
	{
		if(tab->wdt > 0 && tab->wdt - precision_len > 0 && tab->dash == 0)
		{
			
			if(tab->zero == 1)
			{
				k = 0;
				while(k < (tab->wdt - precision_len))
					k += write(1, "0", 1);
			}
			else
			{
				k = 0;
				while(k < (tab->wdt - precision_len))
					k += write(1, " ", 1);
			}
		}
		w = 0;
		while(w < precision_len)
		{
			w += write(1, &c[w], 1);
		}
		printf("%d",w);
		printf("%d",tab->wdt);
	}
	// DASH > 0;
	// if(tab->dash > 0)
	// {
	// 	if(tab->dot != 0)
	// 	{
	// 		while(w < (tab->dot -1) && c[w] != '\0')
	// 			w += write(1, &c[w], 1);
	// 		if (tab->dot < 0) //----------negative precision JUST PRINT SPACE
	// 		{
	// 			tab->dot = - 1 * (tab->dot);
	// 			while(w < (tab->dot -1) && c[w] != '\0')
	// 				w += write(1, " ", 1);
	// 			tab->dot = - 1 * (tab->dot);
	// 		}
	// 	}
	// 	if(tab->wdt != 0 && (tab->wdt - ft_strlen(c) > 0 || tab->wdt - (tab->dot - 1)> 0) && tab->dot > 0)// THE CONDITION IN THE MIDDLE with II is cause of this: ft_printf("#WTF|%3.2s|WTF\n", "DOOM")
	// 	{
	// 		if (tab->dot > 0)
	// 		{
	// 			if (tab->dot -1 >= ft_strlen(c))
	// 				precision_len = ft_strlen(c);
	// 			else
	// 				precision_len = tab->dot -1;
	// 		}
	// 		if(tab->zero == 1 && tab->dot >= 0 && tab->space == 0)
	// 		{
	// 			k = 0;
	// 			while(k < (tab->wdt - precision_len))
	// 				k += write(1, "0", 1);
	// 		}
	// 		else
	// 		{
	// 			k = 0;
	// 			while(k < (tab->wdt - precision_len))
	// 				k += write(1, " ", 1);
	// 		}
	// 	}
	// }
	return (k + w); //is returning 11// '/0' == 0
}