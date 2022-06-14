/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:55:32 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/13 21:27:18 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int	check_valid_arg(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '%')
		return (1);
	while (string[i])
	{
		while (ft_is_in(string[i], "-0 .#+") != -1
			|| (ft_isdigit(string[i]) == 1))
			i++;
		if (ft_is_in(string[i], "cspdiuxX%") != -1)
			return (1);
		else
			return (0);
	}
	return (0);
}
