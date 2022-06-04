/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:00:31 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/04 17:17:10 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_out_ptr(t_out *tab)
{
	// char *tmp;
	char	*c;
	// char *mailbox;
	// int i;
	c = va_arg(tab->args, void *);
	
	// mailbox = &c;
	// while(mailbox[i])
	// {
	// 	printf("mailbox:\t %x  %d\n", mailbox[i], i);
	// 	i++;
	//}//write(1, &mailbox, sizeof(mailbox));
	
	return 0;
}