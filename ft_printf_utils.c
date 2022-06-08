/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:55:32 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/09 00:00:35 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int how_big(unsigned long n, int i)
{
	int len;
	
	//printf("%lu", n);
	len = 0;
	while(n > 0)
	{	
		n = n/i;
		len++;
	}
	return (len);
}

int ft_is_in(char c, char *str)
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

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
		
	return (i);
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

int decimal_to_base (unsigned long long  n, char *base) //012456789ABCDEF
{
	int i;
	int z;

	z = 0;
	i = ft_strlen (base);
	
	if (n > 0)
	{
		decimal_to_base(n/i, base);
		write(1, &base[n%i], 1);
	}
	
	z += how_big(n, i);
	
	return (z);
	
} //"10" char base [2] = "0123456789ABCDEF";