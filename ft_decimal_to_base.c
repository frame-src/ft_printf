/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:29:21 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/11 21:04:48 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int decimal_to_string(unsigned long n, char *base)
{
	int i;
	
	i = 0;
	while(base[i])
		i++;
	if (n>0)
	{
		decimal_to_string(n/i, base);
		write(1, &base[n%i], 1);
	}
		if (n == 0)
			write(1, "0", fd);
	return (1);
}

int main ()
{
	char *s;
	s = "achile";
		decimal_to_string(105565656526262, "0123456789ABCDEF");
		printf("\n%p\n", s);
	return 0;
}