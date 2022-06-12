/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:02:32 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/12 22:39:19 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_precision_value( int precision, int len, unsigned int num)
{
	if (precision > len)
		return (precision);
	if (precision == 0 && num == 0)
		return (0);
	else
		return (len);
}

static int	print_unsigned_wdt(t_out *tab, int len)
{
	int			z;

	z = 0;
	if (tab->zero > 0 && tab->dot == 0)
	{
		while (z < tab->wdt - len)
			z += write(1, "0", 1);
	}
	else
	{
		while (z < tab->wdt - len)
			z += write(1, " ", 1);
	}
	return (z);
}

int	ft_print_out_unsigned( t_out *tab)
{
	long int	num;
	size_t		z;
	int			i;
	int			p;

	z = 0;
	i = 0;
	num = va_arg(tab->args, unsigned int);
	p = ft_precision_value(tab->dot -1, how_big(num, 10), num);
	if (tab->wdt != 0 && tab->wdt - p > 0 && tab->dash == 0)
		z += print_unsigned_wdt(tab, p);
	while (i < (tab->dot - 1) - how_big(num, 10))
	{
		z += write(1, "0", 1);
		i++;
	}
	if (num == 0 && tab->dot -1 != 0)
		z += write(1, "0", 1);
	if (num != 0)
		z += decimal_to_base(num, "0123456789");
	if (tab->wdt != 0 && tab->wdt - p > 0 && tab->dash > 0)
		z += print_unsigned_wdt(tab, p);
	return (z);
}
