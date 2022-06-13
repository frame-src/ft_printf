/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:07:41 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/13 20:34:06 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	how_big(unsigned long n, int i)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{	
		n = n / i;
		len++;
	}
	return (len);
}

int	ft_modulo(long int num)
{
	int	sign;

	sign = 1;
	if (num < 0)
		sign = -1;
	return (sign);
}

int	decimal_to_base(unsigned long long n, char *base)
{
	int	i;
	int	z;

	z = 0;
	i = ft_strlen (base);
	if (n > 0)
	{
		decimal_to_base(n / i, base);
		write(1, &base[n % i], 1);
	}
	z += how_big(n, i);
	return (z);
}

int	ft_get_precision( char *num, int i)
{
	int	len;

	len = 0;
	while (ft_isdigit((int)num[i]) != 0)
	{
		len = (len * 10) + ((num[i]) - '0');
		i++;
	}
	return (len + 1);
}

int	ft_get_wdt(char *num, int i)
{
	int		len;

	len = 0;
	while (ft_isdigit((int)num[i]) != 0)
	{
		len = (len * 10) + ((num[i]) - '0');
		i++;
	}
	return (len);
}
