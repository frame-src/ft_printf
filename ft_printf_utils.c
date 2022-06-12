/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:55:32 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/12 20:31:18 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
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
