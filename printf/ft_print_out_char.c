/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:54 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/04 17:13:57 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_out_char(t_out *tab)
{
	int w;
	char c = va_arg(tab->args, int);
	w = write(1,&c,1);
	return w;
}
