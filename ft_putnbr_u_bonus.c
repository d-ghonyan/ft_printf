/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:40:59 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:01 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	_ft_putnbr_u(unsigned int n, char c, int *count, t_flag flags)
{
	if (c == 'x')
		to_hex_lower(n, count, flags);
	else if (c == 'X')
		to_hex_upper(n, count, flags);
	else
	{
		if (n > 9)
			_ft_putnbr_u(n / 10, c, count, flags);
		*count += write(1, &"0123456789"[n % 10], 1);
	}
}

static void	hello(int cond, int a, int *count)
{
	if (cond)
	{
		while(a > 0)
		{
			*count += write (1, " ", 1);
			a--;
		}
	}
}

void	ft_putnbr_u(unsigned int n, char c, int *count, t_flag flags)
{
	int	a;
	int	tf;
	int	prec;


	if (flags.precision && flags.precision_width <= 0 && !n)
		return ;
	prec = flags.precision_width - len_hex(n);
	tf = 0;
	if (prec > 0)
		tf = prec;
	a = flags.width - (len_hex(n) + (flags.space || flags.plus) + tf);
	hello(!flags.minus, a, count);
	if (flags.octo && n)
		*count += write(1, "0x", 2);
	if (flags.plus && n >= 0)
		*count += write(1, "+", 1);
	while (prec > 0)
	{
		*count += write (1, "0", 1);
		prec--;
	}
	if (flags.space && n >= 0 && !flags.plus)
		*count += write(1, " ", 1);
	_ft_putnbr_u(n, c, count, flags);
	hello(flags.minus, a, count);
}