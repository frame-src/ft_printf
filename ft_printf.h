/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmessin <frmessin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:37:21 by frmessin          #+#    #+#             */
/*   Updated: 2022/06/09 00:00:17 by frmessin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_out
{
	va_list	args;		//arguments (content, ...);
	int	wdt;			//width
	int	prf;			//hashtag
	int	zero;			//zero padding
	int	dot;			//.
	int	dash;			//-
	int	tl;				//total_length (return value)
	int	sign;			//pos or neg number
	int	is_zero;		//is number zero
	int	percent;		//%
	int	space;			//space flag ' '
	
}t_out;

t_out	*ft_init_tab(t_out *ptr);
int		how_big(unsigned long n, int i);
int		decimal_to_string(unsigned long long n, char *base);
int		ft_is_in(char c, char *str);
size_t	ft_strlen(char *c);
int		ft_isdigit(int c);
int		ft_print_out_char(t_out *tab);
int		ft_print_out_str(t_out *tab);
int		ft_print_out_ptr(t_out *tab, char *base, char *prefix);
int		ft_print_out_nbr(t_out *tab);
int		ft_get_precision( char *num, int i);
int		ft_get_wdt(char *num, int i);
int		ft_format_output(t_out *tab, char *arg, size_t i);
int		ft_printf(const char *content, ...);
int		decimal_to_base(unsigned long long n, char *base);
int		ft_print_out_unsigned(t_out *tab);
int		ft_print_out_percent(void);
int		ft_print_out_hex(t_out *tab, char *base, char *prefix);


#endif
