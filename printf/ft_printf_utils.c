/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:55:32 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/05 15:02:12 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int how_big(size_t n, int i)
{
	int len;
	
	len = 0;
	while(n > 0)
	{	
		n = n/i;
		len++;
	}
	return (len);
}

int ft_is_in(const char c, char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(c == str[i])
			return i;
		i++;
	}
	return (-1);
}

int	ft_strlen(char *c)
{
	int i = 0;
	while(c[i]!= '\0')
		i++;
	return i;
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int decimal_to_base(unsigned n, char *base)
{
	int i;

	i = 0;
	while(base[i])
		i++;
	if (n>0)
	{
		decimal_to_base(n/i, base);
		write(1, &base[n%i], 1);
	}
	return (how_big(n, i));
}