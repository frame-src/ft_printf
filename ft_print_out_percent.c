/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:04:11 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/04 17:23:46 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_out_percent(t_out *tab)
{
	int w;
	char c;
	c = va_arg(tab->args, int);
	w = write(1,"%",1);
	return w;
}
