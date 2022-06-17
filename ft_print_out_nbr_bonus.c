/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_nbr_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:01:18 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/14 18:57:26 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_precision_value(int precision, int len, int num)
{
	if (precision > len)
		return (precision);
	if (precision == 0 && num == 0)
		return (0);
	else
		return (len);
}

static int	print_nbr_wdt(t_out *tab, int len, int i)
{
	int	z;

	z = 0;
	if (tab->zero > 0 && tab->dot == 0)
	{
		while (i < tab->wdt - len)
		{
			z += write(1, "0", 1);
			i++;
		}
	}
	else
	{
		while (i < tab->wdt - len)
		{
			z += write(1, " ", 1);
			i++;
		}
	}
	return (z);
}

static int	print_out_sign(int sign, int plus_flag, int space)
{
	int	i;

	i = 0;
	if (sign > 0 && (plus_flag > 0 || space > 0))
	{
		if (space == 0)
			i = write(1, "+", 1);
		else
			i = write(1, " ", 1);
	}
	if (sign < 0)
		i = write(1, "-", 1);
	return (i);
}

static int	print_flag_out(t_out *tab, long int num, int i, int sign)
{
	int	p;
	int	z;

	z = 0;
	p = ft_precision_value(tab->dot -1, how_big(num, 10), num);
	if (tab->zero > 0 && tab->dot == 0)
		z += print_out_sign(sign, tab->sign, tab->space);
	if (tab->wdt != 0 && tab->wdt - p > 0 && tab->dash == 0)
		z += print_nbr_wdt(tab, p, i);
	if (tab->zero == 0 || (tab->zero > 0 && tab->dot > 0))
		z += print_out_sign(sign, tab->sign, tab->space);
	i = 0;
	while (i < (tab->dot - 1) - how_big(num, 10))
	{
		z += write(1, "0", 1);
		i++;
	}
	if (num == 0 && tab->dot -1 != 0)
		z += write(1, "0", 1);
	if (num != 0)
		z += decimal_to_base(num, "0123456789");
	return (z);
}

int	ft_print_out_nbr( t_out *tab)
{
	long int	num;
	int			sign;
	int			i;
	size_t		z;
	int			p;

	z = 0;
	num = va_arg(tab->args, int);
	sign = ft_modulo(num);
	num = sign * num;
	i = 0;
	if (tab->sign > 0 || sign == -1)
		i = 1;
	p = ft_precision_value(tab->dot -1, how_big(num, 10), num);
	z += print_flag_out(tab, num, i, sign);
	if (tab->wdt != 0 && tab->wdt - p > 0 && tab->dash > 0)
	{
		i = 0;
		if (sign == -1)
			i = 1;
		z += print_nbr_wdt(tab, p, i);
	}
	return (z);
}
