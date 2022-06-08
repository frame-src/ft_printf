/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:29:21 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/07 14:53:30 by frmessin         ###   ########.fr       */
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
	return (1);
}
// int main (void)
// {
// 	decimal_to_string(-454678941320454,"0123456789ABCDEF");
// 	printf("hex= %0x",-454678941320454);

// return (how_big(n, base));
// }

// char *reversed(char*str)
// {
// 	int	len;
// 	int	i;
// 	char* reverse;

// 	len = 0;
// 	i = 0;
// 	while(str[len])
// 		len++;
// 	reverse = malloc(len + 1);
// 	if(!reverse)
// 		return NULL;
// 	reverse[len] = '\0';
// 	while(str[i])
// 	{
// 		reverse[len - 1] = str[i];
// 		len--;
// 		i++;
// 	}
// 	free (str);
// 		printf("\nreversed:%s\n",(reverse));
// 	return (reverse);
// }

// int how_big(size_t n, int base)
// {
// 	int i;

// 	i = 0;
// 	while(n>0)
// 	{
// 		n = n/base;
// 		i++;
// 	}
// 	return (i);
// }

// char *decimal_to_string(size_t n)
// {
// 	size_t len;
// 	char *converted_bin;
// 	int i;
	
// 	int bin [] = {0,1};
	
// 	len = how_big(n, 2);
// 	printf("len: %d", len);
// 	converted_bin = malloc( len + 1);
// 	if(!converted_bin)
// 		return NULL;
// 	converted_bin[len] = '\0';
	
// 	i = 0;
// 	while( i <= len)//10 -> 10%2 = 0
// 	{
// 		converted_bin[i] = n%2;
// 		printf("\nc_bin:%d\n",converted_bin[i]);
// 		n = n/2;
// 		i++;
// 	}	
// 	return reversed(converted_bin);
// }

// int main ()
// {
// 	char *s;
// 	s = decimal_to_string(10);
// 	printf("\ns:%s",s);
	
// 	return 0;
// }