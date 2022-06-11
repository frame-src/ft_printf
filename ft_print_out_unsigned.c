/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:02:32 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/12 01:11:34 by frmessin         ###   ########.fr       */
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

int	print_unsigned_wdt(int zero, int precision, int width, int len, int i)
{
	int			z;

	z = 0;
	if (zero > 0 && precision == 0)
	{
		while (i < width - len)
		{
			z += write(1, "0", 1);
			i++;
		}
	}
	else
	{
		while (i < width - len)
		{
			z += write(1, " ", 1);
			i++;
		}
	}
	return (z);
}

int	ft_print_out_unsigned( t_out *tab)
{
	long int	num;
	int			sign;
	int			i;
	size_t		z;
	int			p;

	z = 0;
	num = va_arg(tab->args, unsigned int);
	sign = 1;
	if (num < 0)
	{
		num = -1 * num;
		sign = -1;
	}
	i = 0;
	if (tab->sign > 0 || sign == -1)
		i = 1;
	p = ft_precision_value(tab->dot -1, how_big(num, 10), num);
	if (tab->wdt != 0 && tab->wdt - p > 0 && tab->dash == 0)
		z += print_unsigned_wdt(tab->zero, tab->dot, tab->wdt, p, i);
	i = 0;
	while (i < (tab->dot - 1) - how_big(num, 10))
	{
		z += write(1, "0", 1);
		i++;
	}
	if (num == 0 && tab->dot -1 != 0)
	{
		z += write(1, "0", 1);
	}
	if (num != 0)
		z += decimal_to_base(num, "0123456789");
	if (tab->wdt != 0 && tab->wdt - p > 0 && tab->dash > 0)
	{
		i = 0;
		if (sign == -1)
			i = 1;
		z += print_unsigned_wdt(tab->zero, tab->dot, tab->wdt, p, i);
	}
	return (z);
}
